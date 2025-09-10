#include <bits/stdc++.h>
using namespace std;
 
int t = 1, l;
int n, m, q;
vector<vector<int>> g;
vector<int> disc, low, depth;
vector<int> cut;
 
vector<vector<int>> anc;
 
set<pair<int, int>> s;
 
int f(int i, int p){
  disc[i] = low[i] = t++;
  
  if(i == 0) depth[i] = 0;
  else depth[i] = depth[p]+1;
 
  anc[i][0] = p;
  for(int j = 1; j < l; j++) anc[i][j] = anc[i][j-1] == -1 ? anc[i][j-1] : anc[anc[i][j-1]][j-1];
  
  int children = 0;
  for(auto j : g[i]){
    if(j == p) continue;
 
    if(!disc[j]){
      f(j, i);
      children++;
 
      if(disc[i] <= low[j] && i != 0) cut[i] = 1;
      low[i] = min(low[i], low[j]);
    }else low[i] = min(low[i], disc[j]);
  }
 
  return children;
}
 
int lca(int a, int b){
  if(depth[a] > depth[b]) swap(a, b);
 
  int k = depth[b]-depth[a];
  for(int j = 0; j < l; j++){
    if(k & (1<<j)) b = anc[b][j];
  }
 
  if(a == b) return a;
 
  for(int j = l-1; j >= 0; j--){
    if(anc[a][j] != anc[b][j]){
      a = anc[a][j];
      b = anc[b][j];
    }
  }
 
  return anc[a][0];
}

int lca2(int a, int b){
  if(depth[a] > depth[b]) swap(a, b);
 
  int k = depth[b]-depth[a]-1;
  for(int j = 0; j < l; j++){
    if(k & (1<<j)) b = anc[b][j];
  }
 
  return b;
}
 
int main() {
  cin >> n >> m >> q;
  g.resize(n);
  disc = low = depth = cut = vector<int>(n, 0);
  
  l = log2(n)+2;
  anc.resize(n, vector<int>(l, -1));
 
  int a, b, c;
  for(int i = 0; i < m; i++){
    cin >> a >> b; a--; b--;
 
    if(s.count({b, a}) || s.count({a, b})) continue;
    s.insert({a, b});
 
    g[a].push_back(b);
    g[b].push_back(a);
  }
 
  if(f(0, -1) != 1) cut[0] = 1;
 
  while(q--){
    cin >> a >> b >> c;
    a--; b--; c--;

    if(a == c || b == c) cout << "NO";
    else if(a == b || !cut[c]) cout << "YES";
    else{
      int real = lca(a, b);

      int checka = lca(a, c), checkb = lca(b, c);
      int roota = (checka == c) ? lca2(a, c) : 0, rootb = (checkb == c) ? lca2(b, c) : 0;

      if(checka == c && checkb == c){
        if(real == c){
          if(low[roota] < disc[c] && low[rootb] < disc[c]) cout << "YES";
          else cout << "NO";
        }else cout << "YES";
      }else if(checka == c){
        if(low[roota] < disc[c]) cout << "YES";
        else cout << "NO";
      }else if(checkb == c){
        if(low[rootb] < disc[c]) cout << "YES";
        else cout << "NO";
      }else cout << "YES";
    }

    cout << endl;
  }
}