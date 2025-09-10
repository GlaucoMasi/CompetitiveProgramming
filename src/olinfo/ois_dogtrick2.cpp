#include <bits/stdc++.h>
using namespace std;

int n, k, m;
vector<int> t;
vector<vector<int>> g, inv, gcomp;
vector<unordered_set<int>> nxt;

int idx = 0;
vector<int> comp, ord, in;
vector<bool> vis, added;

vector<int> topo, pos;

void f1(int i){
  vis[i] = 1;
  for(auto j : g[i]) if(!vis[j]) f1(j);
  ord.push_back(i);
}

void f2(int i, int col){
  comp[i] = col;
  for(auto j : inv[i]) if(comp[j] == -1) f2(j, col);
}

void f3(int i){
  vis[i] = 1;

  for(auto j : g[i]) if(comp[i] != comp[j] && !added[comp[j]]){
    gcomp[comp[i]].push_back(comp[j]);
    in[comp[j]]++;
  }
  
  for(auto j : g[i]) if(!vis[j] && comp[i] == comp[j]) f3(j);
}

bool find(int i, int j){
  if(i == j) return 1;
  if(pos[j] < pos[i]) return 0;

  for(auto k : gcomp[i]){
    if(pos[j] < pos[k]) continue;
    if(find(k, j)) return 1;
  }

  return 0;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  cin >> n >> k;
  t.resize(n);
  for(auto &i : t){
    cin >> i;
    i--;
  }

  cin >> m;
  g.resize(k); inv.resize(k); nxt.resize(k);
  for(int i = 0; i < m; i++){
    int a, b; cin >> a >> b;
    g[--a].push_back(--b);
    inv[b].push_back(a);
    nxt[a].insert(b);
  }

  vis.resize(k); comp.resize(k, -1);
  for(int i = 0; i < k; i++) if(!vis[i]) f1(i);
  for(int i = k-1; i >= 0; i--) if(comp[ord[i]] == -1) f2(ord[i], idx++);

  gcomp.resize(idx); in.resize(idx);
  vis.clear(); vis.resize(k);
  for(int i = 0; i < k; i++){
    if(vis[i]) continue;
    added.clear(); added.resize(idx);
    f3(i);
  }

  queue<int> q; for(int i = 0; i < idx; i++) if(!in[i]) q.push(i);
  while(!q.empty()){
    auto i = q.front(); q.pop();
    topo.push_back(i);
    for(auto j : gcomp[i]) if(--in[j] == 0) q.push(j);
  }
  
  pos.resize(idx);
  for(int i = 0; i < idx; i++) pos[topo[i]] = i;

  int points = 2;
  for(int i = 1; i < n; i++){
    if(nxt[t[i-1]].count(t[i])) points += 2;
    else if(find(comp[t[i-1]], comp[t[i]])) points++;
    else break;
  }
  
  cout << points;
}