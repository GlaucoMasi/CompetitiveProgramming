#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int n, m, k;
vector<int> path;
vector<vector<int>> c;
vector<vector<pair<int, int>>> g;

int flow(vector<pair<int, int>> &fat){
  vector<int> dist(n, 1e9);
  vector<bool> in(n);
  queue<int> q;
  
  q.push(0); dist[0] = 0; in[0] = 1;
  while(!q.empty()){
    int i = q.front(); q.pop();
    in[i] = 0;

    for(auto [j, cost] : g[i]){
      if(dist[j] <= dist[i]+cost || (cost == 1 && c[i][j] == -1) || (cost == -1 && c[j][i] == 1)) continue;
      fat[j] = {i, cost};
      dist[j] = dist[i]+cost;
      if(!in[j]){
        in[j] = 1;
        q.push(j);
      }
    }
  }

  return dist[n-1] != 1e9 ? dist[n-1] : -1;
}

void f(int i){
  path.push_back(i);
  if(i == n-1) return;

  for(auto [j, cost] : g[i]){
    if(cost == -1 || c[i][j] == 1) continue;
    c[i][j] = 1;
    f(j);
    return;
  }
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  cin >> n >> m >> k;
  c.resize(n, vector<int>(n));
  g.resize(n);

  for(int i = 0; i < m; i++){
    int a, b; cin >> a >> b;
    g[--a].push_back({--b, 1});
    g[b].push_back({a, -1});
    c[a][b] = 1;
  }

  int a, cost = 0;
  vector<pair<int, int>> fat(n);
  for(int i = 0; i < k; i++){
    a = flow(fat);
    cost += a;

    if(a == -1){
      cout << -1;
      return 0;
    }

    int j = n-1;
    while(j != 0){
      if(fat[j].second == 1) c[fat[j].first][j] = -1;
      else c[j][fat[j].first] = 1;
      j = fat[j].first;
    }
  }

  cout << cost << '\n';
  for(int i = 0; i < k; i++){
    path.clear(); f(0);
    cout << path.size() << '\n';
    for(auto i : path) cout << i+1 << " ";
    cout << '\n';
  }
}