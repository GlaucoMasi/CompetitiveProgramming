#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5;

int n, q;
int v[maxn];
vector<int> g[maxn];

int curr = 0;
int head[maxn], idx[maxn], heavy[maxn], sz[maxn], depth[maxn], fat[maxn];
vector<int> vals;

struct st{
  int sz = 1;
  vector<int> v;

  st(vector<int> &data){
    while(sz < data.size()) sz *= 2;
    v.resize(2*sz, 0);
    build(1, 0, sz, data);
  }

  void build(int u, int l, int r, vector<int> &data){
    if(l == r-1){
      if(l < data.size()) v[u] = data[l];
    }else{
      build(2*u, l, l+(r-l)/2, data);
      build(2*u+1, l+(r-l)/2, r, data);
      v[u] = max(v[2*u], v[2*u+1]);
    }
  }

  void upd(int p, int value){
    for (v[p += sz] = value; p > 1; p >>= 1) v[p>>1] = max(v[p], v[p^1]);
  }

  int get(int l, int r){
    int res = 0;
    for (l += sz, r += sz; l < r; l >>= 1, r >>= 1) {
      if (l&1) res = max(res, v[l++]);
      if (r&1) res = max(res, v[--r]);
    }
    return res;
  }
};

void dfs(int i, int p){
  if(p != -1) depth[i] = depth[p]+1;
  fat[i] = p; sz[i] = 1; heavy[i] = -1;

  int big = -1;
  for(auto j : g[i]){
    if(j == p) continue;
    dfs(j, i);
    sz[i] += sz[j];

    if(sz[j] > big){
      big = sz[j];
      heavy[i] = j;
    }
  }
}

void hld(int i, int h){
  head[i] = h;
  idx[i] = curr++;
  vals.push_back(v[i]);
  if(heavy[i] != -1) hld(heavy[i], h);
  for(auto j : g[i]) if(j != fat[i] && j != heavy[i]) hld(j, j);
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  cin >> n >> q;
  for(int i = 0; i < n; i++) cin >> v[i];

  for(int i = 0; i < n-1; i++){
    int a, b; cin >> a >> b;
    g[--a].push_back(--b);
    g[b].push_back(a);
  }

  dfs(0, -1);
  hld(0, 0);
  st st(vals);

  while(q--){
    int t; cin >> t;

    if(t == 1){
      int s, x; cin >> s >> x;
      st.upd(idx[s-1], x);
    }else{
      int a, b; cin >> a >> b; a--; b--;

      int ans = 0;
      for(; head[a] != head[b]; b = fat[head[b]]){
        if(depth[head[a]] > depth[head[b]]) swap(a, b);
        ans = max(ans, st.get(idx[head[b]], idx[b]+1));
      }

      if(depth[a] > depth[b]) swap(a, b);
      ans = max(ans, st.get(idx[a], idx[b]+1));

      cout << ans << " ";
    }
  }
}