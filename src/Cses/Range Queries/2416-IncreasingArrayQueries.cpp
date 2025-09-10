#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

const int maxn = 2e5+1;
long long fw[maxn];

void upd(int i, long long k){
  i++; k -= fw[i];
  while(i < maxn){
    fw[i] += k;
    i += (i&-i);
  }
}

long long get(int i){
  i++; long long ans = 0;
  while(i > 0){
    ans += fw[i];
    i -= (i&-i);
  }
  return ans;
}

int main() {
  int n, q; cin >> n >> q;
  vector<vector<pair<int, int>>> quer(n);
  vector<long long> cum(n), ans(q);
  vector<int> v(n);

  for(auto &i : v) cin >> i;
  cum[0] = v[0];
  for(int i = 1; i < n; i++) cum[i] = cum[i-1]+v[i];

  for(int i = 0; i < q; i++){
    int a, b; cin >> a >> b;
    quer[a-1].push_back({b, i});
  }

  vector<pair<int, int>> s; s.push_back({2e9, n});
  for(int i = n-1; i >= 0; i--){
    while(s.back().first < v[i]){
      upd(s.back().second, 0);
      s.pop_back();
    }

    upd(i, (long long)(s.back().second-i)*v[i]);
    s.push_back({v[i], i});

    for(auto [end, idx] : quer[i]){
      int l = 0, r = s.size();
      while(l < r-1){
        int m = (l+r)/2;
        if(s[m].second > end) l = m;
        else r = m;
      } l++;

      long long part = get(s[l].second-1);
      part += (long long)(end-s[l].second)*s[l].first;
      part -= cum[end-1] - (i ? cum[i-1] : 0);
      ans[idx] = part;
    }
  }

  for(auto i : ans) cout << i << '\n';
}