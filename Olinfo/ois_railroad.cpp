#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<pair<int, int>>> g;

vector<long long> dijkstra(int i){
  vector<long long> d(n, 1e18);
  vector<bool> vis(n);
  priority_queue<pair<long long, int>> pq;

  d[i] = 0;
  pq.push({0, i});
  while(!pq.empty()){
    int node = pq.top().second; pq.pop();

    if(vis[node]) continue;
    vis[node] = 1;

    for(auto i : g[node]){
      if(d[i.first] > d[node]+i.second){
        d[i.first] = d[node]+i.second;
        pq.push({-d[i.first], i.first});
      }
    }
  }

  return d;
}

int main() {
  cin >> n >> m;
  g.resize(n);

  int a, b, c;
  for(int i = 0; i < m; i++){
    cin >> a >> b >> c;
    g[a].push_back({b, c});
    g[b].push_back({a, c});
  }

  vector<long long> start = dijkstra(0), end = dijkstra(n-1);

  long long ans = 1e18;
  for(int a = 0; a < n; a++){
    for(auto [b, c] : g[a]){
      if(a > b) continue;
      if(start[a]+end[a] == start[n-1] && start[b]+end[b] == start[n-1]) continue;

      long long path = min(start[a]+end[b], start[b]+end[a]) + c;
      if(c > path-start[n-1]+1) ans = min(ans, path-start[n-1]+1);
    }
  }

  cout << (ans == 1e18 ? -1 : ans);
}