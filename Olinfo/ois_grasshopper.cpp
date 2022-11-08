#include <bits/stdc++.h>
using namespace std;

int n, m, tot = 0;
vector<vector<bool>> vis;
vector<vector<int>> g;

void f(int i, bool par){
  if(!par) tot++;
  vis[i][par] = 1;

  for(auto j : g[i])
    if(!vis[j][!par]) f(j, !par);
}

int main() {
  cin >> n >> m;
  vis.resize(n, vector<bool>(2));
  g.resize(n);

  int a, b;
  for(int i = 0; i < m; i++){
    cin >> a >> b;
    g[a].push_back(b);
  }

  f(0, 0);

  cout << tot;
}