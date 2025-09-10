#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m, t;
  cin >> n >> m >> t;

  vector<vector<pair<int, pair<int, int>>>> g(n);
  int a, b, c, d;
  for(int i = 0; i < m; i++){
    cin >> a >> b >> c >> d;
    g[a].push_back({b, {c, d}});
  }

  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  vector<int> dist(n, 1e9);
  vector<bool> vis(n, 0);
  dist[0] = 0;
  pq.push({0, 0});
  while(!pq.empty()){
    int node = pq.top().second; pq.pop();

    if(node == n-1) break;

    if(vis[node]) continue;
    vis[node] = 1;
  
    for(auto i : g[node]){
      if(i.second.second && dist[node] + i.second.first > t) continue;

      if(dist[node] + i.second.first < dist[i.first]){
        dist[i.first] = dist[node] + i.second.first;
        pq.push({dist[i.first], i.first});
      }
    }
  }

  cout << (dist[n-1] == 1e9 ? -1 : dist[n-1]);
}