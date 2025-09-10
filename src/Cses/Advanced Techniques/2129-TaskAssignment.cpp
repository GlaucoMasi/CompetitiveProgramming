#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int n, m;
vector<vector<int>> c;
vector<vector<pair<int, int>>> g;

int flow(vector<int> &fat){
  vector<int> dist(m, 1e9);
  vector<bool> in(m);
  queue<int> q;

  dist[0] = 0; in[0] = 1; q.push(0);
  while(!q.empty()){
    int i = q.front(); q.pop(); in[i] = 0;
    
    for(auto [j, cost] : g[i]){
      if(!c[i][j] || dist[j] <= dist[i]+cost) continue;
      dist[j] = dist[i]+cost;
      fat[j] = i;
      if(!in[j]){
        q.push(j);
        in[j] = 1;
      }
    }
  }

  return dist[2*n+1];
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  cin >> n; m = 2*n+2;
  g.resize(m);
  c.resize(m, vector<int>(m));
  for(int i = 1; i <= n; i++) for(int j = n+1; j <= 2*n; j++){
    int a; cin >> a;
    g[i].push_back({j, a});
    g[j].push_back({i, -a});
    c[i][j] = 1;
  }

  for(int i = 1; i <= n; i++){
    g[0].push_back({i, 0});
    g[i].push_back({0, 0});
    c[0][i] = 1;
  }

  for(int j = n+1; j <= 2*n; j++){
    g[j].push_back({2*n+1, 0});
    g[2*n+1].push_back({j, 0});
    c[j][2*n+1] = 1;
  }

  int cost = 0;
  vector<int> fat(m);
  for(int i = 0; i < n; i++){
    cost += flow(fat);

    int j = 2*n+1;
    while(j != 0){
      c[fat[j]][j]--;
      c[j][fat[j]]++;
      j = fat[j];
    }
  }

  cout << cost << '\n';
  for(int i = 1; i <= n; i++){
    for(int j = n+1; j <= 2*n; j++){
      if(!c[i][j]){
        cout << i << " " << j-n << '\n';
        break;
      }
    }
  }
}