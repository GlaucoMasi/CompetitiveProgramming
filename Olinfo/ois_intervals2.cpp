#include <bits/stdc++.h>
using namespace std;

struct ST{
  int sz;
  vector<int> v;
  
  void init(int n){
    sz = 1; while(sz < n) sz *= 2;
    for(int i = 0; i < min((int)v.size(), 2*sz); i++) v[i] = 0;
    while(v.size() < 2*sz) v.push_back(0);
  }

  void upd(int u){
    u += sz;
    v[u]++;

    while(u > 1){
      u /= 2;
      v[u]++;
    }
  }

  int get(int l, int r){
    int ans = 0;

    for(l += sz, r += sz; l < r; l /= 2, r /= 2){
      if(l&1) ans += v[l++];
      if(r&1) ans += v[--r];
    }

    return ans;
  }
};

ST st;

void solve() {
  int n; cin >> n;
  vector<long long> v(n); for(auto &i : v) cin >> i;

  vector<vector<int>> intv(n);
  for(int i = 0; i < n; i++){
    for(int j = 1; i+j-1 < n; j++){
      if(!(v[i+j-1]%j)) intv[i+j-1].push_back(i);
      else break;
    }
  }

  st.init(n+1);
  
  int q; cin >> q;
  vector<int> r, ans(q);
  vector<unordered_map<int, vector<int>>> quer(n);
  for(int i = 0; i < q; i++){
    int a, b; cin >> a >> b;
    r.push_back(--b);
    quer[b][--a].push_back(i);
  }

  int j = -1;
  sort(r.begin(), r.end());
  for(int i = 0; i < q; i++){
    while(j < r[i]){
      j++;
      for(auto k : intv[j]) st.upd(k);
    }

    for(auto j : quer[r[i]]){
      int temp = st.get(j.first, r[i]+1);
      for(auto k : j.second) ans[k] = temp;
    }
  }

  for(auto i : ans) cout << i << '\n';
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int t; cin >> t;
  while(t--) solve();
}