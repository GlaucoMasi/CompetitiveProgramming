#include <bits/stdc++.h>
using namespace std;

struct st{
  int sz = 1;
  vector<long long> v;

  st(vector<int> &data){
    while(sz < data.size()) sz *= 2;
    v.resize(2*sz);
    build(1, 0, sz, data);
  }

  void build(int u, int l, int r, vector<int> &data){
    if(l == r-1){
      if(l < data.size()) v[u] = data[l];
    }else{
      build(2*u, l, l+(r-l)/2, data);
      build(2*u+1, l+(r-l)/2, r, data);
      v[u] = v[2*u]+v[2*u+1];
    }
  }

  void upd(int u, int k){
    u += sz;
    v[u] = k;

    while(u > 1){
      u /= 2;
      v[u] = v[2*u]+v[2*u+1];
    }
  }

  long long get(int u, int l, int r, int x, int y){
    if(l >= y || r <= x) return 0;
    if(l >= x && r <= y) return v[u];
    return get(2*u, l, l+(r-l)/2, x, y)+get(2*u+1, l+(r-l)/2, r, x, y);
  }
};

int n, q;
vector<int> val;
vector<vector<int>> g;
vector<int> sz, ord, idx, dt;

void f(int i, int p) {
  ord.push_back(i);

  for(auto j : g[i]){
    if(j == p) continue;
    f(j, i);
    sz[i] += sz[j];
  }
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  cin >> n >> q;
  g.resize(n); val.resize(n);
  for(auto &i : val) cin >> i;

  for(int i = 0; i < n-1; i++){
    int a, b; cin >> a >> b;
    g[--a].push_back(--b);
    g[b].push_back(a);
  }

  sz.resize(n, 1);
  f(0, -1);

  idx.resize(n);
  for(int i = 0; i < n; i++) idx[ord[i]] = i, dt.push_back(val[ord[i]]);
  st st(dt);

  while(q--){
    int t; cin >> t;

    if(t == 1){
      int s, x; cin >> s >> x;
      st.upd(idx[s-1], x);
    }else{
      int s; cin >> s;
      cout << st.get(1, 0, st.sz, idx[s-1], idx[s-1]+sz[s-1]) << '\n';
    }
  }
}