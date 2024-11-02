#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int n, m, q, idx = 0;
vector<vector<int>> g, inv, cond;
vector<int> ord, comp, topo, pos;
vector<bitset<50000>> reach;
vector<bool> vis;

void dfs(int i){
  vis[i] = 1;
  for(auto j : g[i]) if(!vis[j]) dfs(j);
  ord.push_back(i);
}

void col(int i, int c){
  comp[i] = c;
  for(auto j : inv[i]) if(comp[j] == -1) col(j, c);
}

void merge(int i){
  vis[i] = 0; reach[i].set(i);
  for(auto j : cond[i]){
    if(vis[j]) merge(j);
    reach[i] |= reach[j];
  }
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  cin >> n >> m >> q;
  g.resize(n);
  inv.resize(n);
  vis.resize(n);
  comp.resize(n, -1);

  for(int i = 0; i < m; i++){
    int a, b; cin >> a >> b;
    g[--a].push_back(--b);
    inv[b].push_back(a);
  }

  for(int i = 0; i < n; i++) if(!vis[i]) dfs(i);
  for(int i = n-1; i >= 0; i--) if(comp[ord[i]] == -1) col(ord[i], idx++);

  reach.resize(idx); cond.resize(idx);
  for(int i = 0; i < n; i++) for(auto j : g[i]) if(comp[i] != comp[j]) cond[comp[i]].push_back(comp[j]);
  for(int i = 0; i < idx; i++) if(vis[i]) merge(i);

  while(q--){
    int a, b; cin >> a >> b;
    cout << (reach[comp[--a]][comp[--b]] ? "YES\n" : "NO\n");
  }
}