#include <bits/stdc++.h>
using namespace std;

struct st{
  int sz = 1;
  vector<pair<int, int>> v;

  st(int n){
    while(sz < n) sz *= 2;
    v.resize(2*sz, {0, -1});
  }

  void upd(int u, int k, int i){
    u += sz;
    v[u] = max(v[u], {k, i});

    while(u > 1){
      u /= 2;
      v[u] = max(v[2*u], v[2*u+1]);
    }
  }

  pair<int, int> get(int u, int l, int r, int x, int y){
    if(l >= y || r <= x) return {0, -1};
    if(l >= x && r <= y) return v[u];

    return max(
      get(2*u, l, (l+r)/2, x, y),
      get(2*u+1, (l+r)/2, r, x, y)
    );
  }
};

int main() {
  int n, m, k; cin >> n >> m >> k;
  vector<long long> a(n), b(m);
  for(auto &i : a) cin >> i;
  for(auto &i : b) cin >> i;

  for(int i = 1; i < n; i++) a[i] += a[i-1];
  
  map<long long, int> pref; pref[b[0]] = 0;
  for(int i = 1; i < m; i++){
    b[i] += b[i-1];
    pref[b[i]] = i;
  }

  st st(m); int last;
  vector<int> prev(n);
  for(int i = 0; i < n; i++){
    if(!pref.count(a[i])) continue;
    auto ans = st.get(1, 0, st.sz, 0, pref[a[i]]);
    prev[i] = ans.second;
    st.upd(pref[a[i]], ans.first+1, i);
    if(i == n-1) last = ans.first+1;
  }

  if(pref[a[n-1]] != m-1 || last < k) cout << -1;
  else{
    vector<pair<int, int>> ans;
    int i = n-1;

    while(i != -1){
      ans.push_back({i, pref[a[i]]});
      i = prev[i];
    }

    for(int i = k-1; i > 0; i--) cout << ans[i].first+1 << " "; cout << '\n';
    for(int i = k-1; i > 0; i--) cout << ans[i].second+1 << " "; cout << '\n';
  }
}