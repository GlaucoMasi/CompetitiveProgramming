#include <bits/stdc++.h>
using namespace std;

int n, logn;
vector<int> val;
vector<vector<int>> g;

vector<int> depth;
vector<vector<int>> fat;

struct pst{
  struct node{
    int sum = 0;
    int l = -1, r = -1;
  };

  int size = 1, idx = 0;
  vector<int> roots;
  vector<node> v;

  void init(int n, int pos){
    while(size < n) size *= 2;

    roots.resize(n);
    v.resize(7e6);
    roots[0] = build(0, size, pos);
  }

  int get(){ return idx++; }

  int build(int l, int r, int pos){
    int i = get();

    if(l != r-1) v[i].sum = v[v[i].l = build(l, l + (r-l)/2, pos)].sum + v[v[i].r = build(l + (r-l)/2, r, pos)].sum;
    else if(l == pos) v[i].sum = 1;

    return i;
  }

  int upd(int prev, int l, int r, int pos){
    if(pos < l || pos >= r) return prev;

    int i = get();

    if(l != r-1) v[i].sum = v[v[i].l = upd(v[prev].l, l, l + (r-l)/2, pos)].sum + v[v[i].r = upd(v[prev].r, l + (r-l)/2, r, pos)].sum;
    else v[i].sum = v[prev].sum+1;

    return i;
  }

  int query(int a, int b, int lca, int value, int l, int r, int k){
    if(l == r-1) return l+1;
    
    int right = v[v[a].r].sum + v[v[b].r].sum - 2*v[v[lca].r].sum + (value >= l + (r-l)/2 && value < r);
    
    if(right >= k) return query(v[a].r, v[b].r, v[lca].r, value, l + (r-l)/2, r, k);
    else return query(v[a].l, v[b].l, v[lca].l, value, l, l + (r-l)/2, k-right);
  }
};

pst st;

void dfs(int i, int p){
  if(i != 0){
    st.roots[i] = st.upd(st.roots[p], 0, st.size, val[i]);
    depth[i] = depth[p]+1;
  }

  fat[i][0] = p;
  for(int j = 1; j < logn; j++){
    if(fat[i][j-1] != -1) fat[i][j] = fat[fat[i][j-1]][j-1];
    else break;
  }

  for(auto j : g[i]) dfs(j, i);
}

int getlca(int a, int b){
  if(depth[a] > depth[b]) swap(a, b);

  int k = depth[b]-depth[a];
  for(int i = 0; i < logn; i++){
    if(k & (1<<i)) b = fat[b][i];
  }

  if(a == b) return a;

  for(int i = logn-1; i >= 0; i--){
    if(fat[a][i] != fat[b][i]) a = fat[a][i], b = fat[b][i];
  }

  return fat[a][0];
}

int main() {
  cin >> n;
  logn = log2(n)+2;

  val.resize(n);
  for(auto &i : val) cin >> i;
  for(auto &i : val) i--;

  g.resize(n);
  for(int i = 1; i < n; i++){
    int a; cin >> a;
    g[a-1].push_back(i);
  }

  depth.resize(n, 0);
  fat.resize(n, vector<int>(logn, -1));
  st.init(n, val[0]);
  dfs(0, -1);
  
  int q; cin >> q;
  while(q--){
    int a, b, k;
    cin >> a >> b >> k;
    a--; b--; int lca = getlca(a, b);
    cout << st.query(st.roots[a], st.roots[b], st.roots[lca], val[lca], 0, st.size, k) << '\n';
  }
}