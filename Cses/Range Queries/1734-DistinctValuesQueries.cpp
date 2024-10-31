#include <bits/stdc++.h>
using namespace std;

constexpr int block = 440;

bool c(const array<int, 3> &a, const array<int, 3> &b){
  if(a[0]/block != b[0]/block) return a[0]<b[0];
  
  if((a[0]/block)%2) return a[1] > b[1];
  else return a[1] < b[1];
}

int main() {
  int n, q; cin >> n >> q;

  int idx = 0;
  map<int, int> comp;
  vector<int> v(n); for(auto &i : v){
    cin >> i;

    if(comp.count(i)) i = comp[i];
    else{
      comp[i] = idx++;
      i = comp[i];
    }
  }
  
  vector<array<int, 3>> quer(q);
  for(int i = 0; i < q; i++){
    cin >> quer[i][0] >> quer[i][1]; quer[i][2] = i;
    quer[i][0]--; quer[i][1]--;
  }

  sort(quer.begin(), quer.end(), c);

  int t = 1;
  vector<int> m(n);
  int l = 0, r = 0; m[v[0]] = 1;
  vector<int> ans(q);
  for(auto [l1, r1, i] : quer){
    while(r1 != r){
      if(r1 > r){
        r++;
        m[v[r]]++;
        if(m[v[r]] == 1) t++;
      }else{
        m[v[r]]--;
        if(m[v[r]] == 0) t--;
        r--;
      }
    }

    while(l1 != l){
      if(l1 > l){
        m[v[l]]--;
        if(m[v[l]] == 0) t--;
        l++;
      }else{
        l--;
        m[v[l]]++;
        if(m[v[l]] == 1) t++;
      }
    }

    ans[i] = t;
  }

  for(auto i : ans) cout << i << '\n';
}