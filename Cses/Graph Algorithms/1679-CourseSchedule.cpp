#include <bits/stdc++.h>
using namespace std;

int n, m;
int t = 0;
vector<int> tempo;
vector<int> ord;
vector<vector<int>> g;
vector<bool> b;

void dfs(int x){
  if(b[x]){
    cout << "IMPOSSIBLE";
    exit(0);
  }

  b[x] = 1;

  for(auto y : g[x]){
    if(tempo[y] == -1) dfs(y);
  }

  t++;
  tempo[x] = t;
  ord.push_back(x);
}

int main() {
  cin >> n >> m;
  g.resize(n);
  tempo.resize(n, -1);
  b.resize(n);

  for(int i = 0; i < m; i++){
    int a, b; cin >> a >> b; a--; b--;

    g[b].push_back(a);
  }

  for(int i = 0; i < n; i++){
    if(tempo[i] == -1) dfs(i);
  }

  for(auto i : ord) cout << i+1 << " ";
}
