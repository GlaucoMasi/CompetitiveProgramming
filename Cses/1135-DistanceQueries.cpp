#include <bits/stdc++.h>
using namespace std;

int n, q;
vector<vector<int>> g, v;
vector<int> depth;

void dfs(int u, int father){
  if(u != 0){ 
    depth[u] = depth[father]+1;

    v[u][0] = father;
    for(int j = 1; j < log2(2*n); j++){
      v[u][j] = v[u][j-1] == -1 ? -1 : v[v[u][j-1]][j-1];
    }
  }

  for(auto i : g[u])
    if(depth[i] == -1) dfs(i, u);
}

int lca(int a, int b){
  if(depth[a] < depth[b]) swap(a, b);
  
  int k = depth[a]-depth[b];
  for(int j = 0; j < log2(2*n); j++){
    if(k & (1<<j)) a = v[a][j];
  }

  if(a == b) return a;

  for(int j = log2(2*n); j >= 0; j--){
    if(v[a][j] != v[b][j]){
      a = v[a][j];
      b = v[b][j];
    } 
  }

  return v[a][0];
}

int main() {
  cin >> n >> q;
  g.resize(n);
  depth.resize(n, -1);
  v.resize(n, vector<int>(log2(4*n)));
  depth[0] = 1;
  for(auto &i : v[0]) i = -1;

  int a, b;
  for(int i = 0; i < n-1; i++){
    cin >> a >> b;
    a--; b--;

    g[a].push_back(b);
    g[b].push_back(a);
  }

  dfs(0, -1);

  while(q--){
    cin >> a >> b;
    a--; b--;

    int k = lca(a, b);

    cout << depth[a] + depth[b] - 2*depth[k] << endl;
  }
}