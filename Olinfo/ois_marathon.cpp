#include <bits/stdc++.h>
using namespace std;

int n, q;
vector<vector<int>> g;
vector<int> ord, status, depth;
vector<pair<int, int>> idx;
vector<vector<int>> anc;

struct st{
  int sz = 1;
  vector<int> v;

  st(int n){
    while(sz < n) sz *= 2;
    v.resize(2*sz);
  }

  void upd(int u, int k){
    u += sz;
    v[u] += k;

    while(u > 1){
      u /= 2;
      v[u] += k;
    }
  }

  int get(int u, int l, int r, int x, int y){
    if(l >= y || r <= x) return 0;
    if(l >= x && r <= y) return v[u];
    return get(2*u, l, (l+r)/2, x, y) + get(2*u+1, (l+r)/2, r, x, y);
  }
};

void euler(int i, int f){
  anc[i][0] = f;
  if(f != -1) depth[i] = depth[f]+1;
  for(int j = 1; j <= 20; j++){
    if(anc[i][j-1] == -1) break;
    anc[i][j] = anc[anc[i][j-1]][j-1];
  }

  ord.push_back(i);
  for(auto j : g[i]) if(j != f) euler(j, i);
  ord.push_back(i);
}

int lca(int a, int b){
  if(depth[a] > depth[b]) swap(a, b);

  int k = depth[b]-depth[a];
  for(int j = 0; j <= 20; j++) if(k&(1<<j)) b = anc[b][j];

  if(a == b) return a;

  for(int j = 20; j >= 0; j--){
    if(anc[a][j] != anc[b][j]){
      a = anc[a][j];
      b = anc[b][j];
    }
  }

  return anc[a][0];
}

int main() {
  cin >> n >> q;
  g.resize(n);
  idx.resize(n, {-1, -1});
  status.resize(n);
  anc.resize(n, vector<int>(21, -1));
  depth.resize(n);

  for(int i = 0; i < n-1; i++){
    int a, b; cin >> a >> b;
    g[--a].push_back(--b);
    g[b].push_back(a);
  }

  euler(0, -1);
  for(int i = 0; i < 2*n; i++){
    if(idx[ord[i]].first == -1) idx[ord[i]].first = i;
    else idx[ord[i]].second = i;
  }

  st st(2*n);
  int sum = 0;
  while(q--){
    int t, x, y;
    cin >> t >> x >> y;

    if(t == 1){
      x--; y--;
      if(anc[y][0] != x) swap(x, y);

      st.upd(idx[y].first, status[y] ? -1 : 1);
      st.upd(idx[y].second, status[y] ? 1 : -1);

      status[y]++; status[y] %= 2;
    }else{
      x = (x+sum)%n; y = (y+sum)%n;
      int t = !(st.get(1, 0, st.sz, 0, idx[x].first+1) +
              st.get(1, 0, st.sz, 0, idx[y].first+1) -
              2*st.get(1, 0, st.sz, 0, idx[lca(x, y)].first+1));
      cout << t << '\n';
      sum += t;
    }
  }
}