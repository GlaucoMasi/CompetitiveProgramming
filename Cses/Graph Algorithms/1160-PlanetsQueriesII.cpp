#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");
 
int n, q, idx = -1;
vector<vector<int>> g, fat;
vector<int> nxt, len, status, depth, root, comp, pos, p;
 
void col(int i){
  comp[i] = idx;
  for(auto j : g[i]) if(comp[j] == -1) col(j);
}
 
void tree(int i, int p){
  if(p != -1) depth[i] = depth[p]+1, root[i] = root[p];
  fat[i][0] = p;
  for(int j = 1; j <= 30; j++){
    if(fat[i][j-1] == -1) break;
    fat[i][j] = fat[fat[i][j-1]][j-1];
  }
 
  for(auto j : g[i]) if(j != p && len[j] == -1) tree(j, i);
}
 
void find(int i){
  if(status[i] == 1){
    int j = i;
    vector<int> path;
    do{
      j = p[j];
      path.push_back(j);
    }while(j != i);
 
    for(auto j : path) len[j] = path.size();
    for(int j = 0; j < path.size(); j++) pos[path[j]] = path.size()-j-1;
    for(auto j : path) root[j] = j, tree(j, -1);
 
    status[i] = 2;
    return;
  }
 
  status[i] = 1;
  if(status[nxt[i]] != 2) p[nxt[i]] = i, find(nxt[i]);
  status[i] = 2;
}
 
void lca(int a, int b){
  if(depth[a] > depth[b]){
    int k = depth[a]-depth[b];
    for(int j = 0; j <= 30; j++) if(k & (1<<j)) a = fat[a][j];
    if(a == b){
      cout << k << '\n';
      return;
    }
  }
  
  cout << "-1\n";
}
 
int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  
  cin >> n >> q;
  fat.resize(n, vector<int>(31, -1));
  comp.resize(n, -1);
  len.resize(n, -1);
  status.resize(n);
  depth.resize(n);
  root.resize(n);
  nxt.resize(n);
  pos.resize(n);
  p.resize(n);
  g.resize(n);
  
  for(int i = 0; i < n; i++){
    cin >> nxt[i]; nxt[i]--;
    g[i].push_back(nxt[i]);
    g[nxt[i]].push_back(i);
  }
  
  for(int i = 0; i < n; i++){
    if(comp[i] == -1){
      idx++;
      col(i);
    }
  }
 
  for(int i = 0; i < n; i++) if(!status[i]) find(i);
 
  while(q--){
    int a, b; cin >> a >> b; a--; b--;
 
    if(a == b) cout << "0\n";
    else if(comp[a] != comp[b] || (len[a] == -1 && len[b] == -1 && root[a] != root[b])) cout << "-1\n";
    else if(root[a] == root[b]) lca(a, b);
    else if(len[b] == -1) cout << "-1\n";
    else{
      int ans = depth[a];a = root[a];
      if(pos[b] >= pos[a]) ans += pos[b]-pos[a];
      else ans += pos[b]+len[a]-pos[a];
      cout << ans << '\n';
    }
  }
}