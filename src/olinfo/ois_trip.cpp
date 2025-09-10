#include <bits/stdc++.h>
using namespace std;

int main() {
  int n; cin >> n;
  int s, e; cin >> s >> e;
  int m; cin >> m;

  int a, b, c, d;
  vector<vector<pair<int, pair<int, int>>>> g(n);
  for(int i = 0; i < m; i++){
    cin >> a >> b >> c >> d;
    g[a].push_back({c, {b, d}});
  }
  
  priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
  vector<int> dist(n, 1e9);
  vector<bool> vis(n);

  pq.push({0, s});
  dist[s] = 0;
  
  while(!pq.empty()){
    auto curr = pq.top(); pq.pop();

    if(curr.second == e) break;
    if(vis[curr.second]) continue;
    vis[curr.second] = 1;

    for(auto i : g[curr.second]){
      if(dist[curr.second] <= i.second.first && dist[i.first] > dist[curr.second] + (i.second.second-dist[curr.second])){
        dist[i.first] = dist[curr.second] + (i.second.second-dist[curr.second]);
        pq.push({dist[i.first], i.first});
      }
    }
  }

  if(dist[e] < 1e9) cout << dist[e];
  else cout << "IMPOSSIBLE";
}