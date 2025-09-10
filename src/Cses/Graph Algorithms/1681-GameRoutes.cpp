#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> g;
vector<int> ord;
vector<bool> vis;
vector<int> num;
int MOD = 1e9 + 7;

// faccio topologico
// sommo avendo grafo

void o(int x){
  vis[x] = 1;

  for(auto y : g[x])
    if(!vis[y]) o(y);

  ord.push_back(x);
}

int main() {
  cin >> n >> m;
  g.resize(n);
  vis.resize(n);
  num.resize(n, 0);

  for(int i = 0; i < m; i++){
    int a, b; cin >> a >> b; a--; b--;

    g[a].push_back(b);
  }

  num[n-1] = 1;

  for(int i = 0; i < n; i++) if(!vis[i]) o(i);

  for(auto i : ord){
    for(auto e : g[i]){
      num[i] = (num[i] + num[e]) % MOD;
    }
  }

  cout << num[0];
}