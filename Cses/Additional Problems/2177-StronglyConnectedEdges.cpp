#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

bool found = 0;
int n, m, idx = 0;

vector<bool> vis;
vector<int> t, low, used;
vector<pair<int, int>> ans;
vector<vector<pair<int, int>>> g;

void f(int i, int p){
  vis[i] = 1;
  low[i] = t[i] = idx++;

  for(auto [j, idx] : g[i]){
    if(j == p) continue;

    if(vis[j]) low[i] = min(low[i], t[j]);
    else{
      f(j, i);
      low[i] = min(low[i], low[j]);
      if(low[j] > t[i]) found = 1;
    }
  }
}

void ass(int i, int p){
  vis[i] = 0;
  for(auto [j, idx] : g[i]){
    if(!used[idx]) cout << i+1 << " " << j+1 << '\n', used[idx] = 1;
    if(vis[j]) ass(j, i);
  }
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  cin >> n >> m;
  g.resize(n);
  t.resize(n);
  vis.resize(n);
  low.resize(n);
  used.resize(m);

  for(int i = 0; i < m; i++){
    int a, b; cin >> a >> b;
    g[--a].push_back({--b, i});
    g[b].push_back({a, i});
  }

  f(0, -1);
  if(found || idx != n) cout << "IMPOSSIBLE";
  else ass(0, -1);
}