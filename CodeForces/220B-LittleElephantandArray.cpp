#include <bits/stdc++.h>
using namespace std;

constexpr int bl = 512;
bool c(const array<int, 3> &a, const array<int, 3> &b){
  if(a[0]/bl != b[0]/bl) return a[0] < b[0];

  if((a[0]/bl)%2) return a[1] > b[1];
  else return a[1] < b[1];
}

int main() {
  int n, q; cin >> n >> q;

  int idx = 0;
  map<int, int> m;
  vector<int> orig;
  vector<int> v(n); for(auto &i : v){
    cin >> i;

    if(!m.count(i)){
      m[i] = idx++;
      orig.push_back(i);
    }

    i = m[i];
  }

  vector<int> ans(q);
  vector<array<int, 3>> queries;
  for(int i = 0; i < q; i++){
    int a, b; cin >> a >> b;
    queries.push_back({--a, --b, i});
  }
  sort(queries.begin(), queries.end(), c);

  int t = 0, l = 0, r = -1;
  vector<int> freq(idx);

  auto add = [&](int i){
    freq[v[i]]++;
    if(freq[v[i]] == orig[v[i]]) t++;
    else if(freq[v[i]]-1 == orig[v[i]]) t--;
  };

  auto remove = [&](int i){
    freq[v[i]]--;
    if(freq[v[i]] == orig[v[i]]) t++;
    else if(freq[v[i]]+1 == orig[v[i]]) t--;
  };

  for(auto [l1, r1, i] : queries){
    while(r1 > r){
      r++;
      add(r);
    }

    while(l1 < l){
      l--;
      add(l);
    }

    while(r1 < r){
      remove(r);
      r--;
    }

    while(l1 > l){
      remove(l);
      l++;
    }

    ans[i] = t;
  }

  for(auto i : ans) cout << i << '\n';
}