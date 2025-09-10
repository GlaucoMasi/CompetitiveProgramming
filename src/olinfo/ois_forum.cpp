#include <bits/stdc++.h>
using namespace std;

struct st{
  struct node{
    int val = 0, lazy = 0;
  };

  int size = 1;
  vector<node> v;

  st(int n){
    while(size < n) size *= 2;
    v.resize(2*size);
  }

  void passa(int u, int l, int r){
    if(v[u].lazy == 0) return;
    else if(v[u].lazy == -1) v[u].val = 0;
    else if(v[u].lazy == 1) v[u].val = 1;

    if(l != r-1){
      v[2*u].lazy = v[u].lazy;
      v[2*u+1].lazy = v[u].lazy;
    }

    v[u].lazy = 0;
  }

  void upd(int u, int l, int r, int x, int y, int k){
    passa(u, l, r);
    
    if(l >= y || r <= x) return;
    if(l >= x && r <= y) v[u].lazy = k;
    else{
      upd(2*u, l, l + (r-l)/2, x, y, k);
      upd(2*u+1, l + (r-l)/2, r, x, y, k);
    }
  }

  int get(int u, int l, int r, int pos){
    passa(u, l, r);

    if(l == r-1) return v[u].val;
    else{
      int m = l + (r-l)/2;
      if(pos < m) return get(2*u, l, m, pos);
      else return get(2*u+1, m, r, pos);
    }
  }
};

vector<vector<int>> g;
vector<int> sz, ord;

int f(int i){
  ord.push_back(i);
  
  sz[i] = 1;

  if(i < g.size()) for(auto j : g[i]) sz[i] += f(j);

  return sz[i];
}

int main() {
  int n, m, q;
  cin >> n >> m >> q;
  g.resize(n); sz.resize(n+m, 0);

  for(int i = 0; i < n+m; i++){
    int a; cin >> a;
    if(a != -1) g[a].push_back(i);
  }

  f(0);

  vector<int> idx(n+m);
  for(int i = 0; i < n+m; i++) idx[ord[i]] = i;

  st st(n+m);

  for(int i = 0; i < q; i++){
    int a, b; cin >> a >> b;

    if(a == 2) cout << st.get(1, 0, st.size, idx[b]) << '\n';
    else st.upd(1, 0, st.size, idx[b], idx[b]+sz[b], a ? 1 : -1);
  }
}