#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m; cin >> n >> m;
  vector<vector<pair<int, int>>> g(n);

  int a, b, c;
  for(int i = 0; i < m; i++){
    cin >> a >> b >> c;
    g[a-1].push_back({b-1, c});
    g[b-1].push_back({a-1, c});
  }

  priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
  vector<bool> vis(n);
  vector<long long> dist(n, -1);

  pq.push({0, 0});
  dist[0] = 0;
  while(!pq.empty()){
    int i = pq.top().second; pq.pop();

    if(i == n-1) break;
    if(vis[i]) continue;
    vis[i] = 1;

    for(auto j : g[i]){
      if(dist[j.first] == -1 || dist[j.first] > dist[i] + j.second){
        dist[j.first] = dist[i] + j.second;
        pq.push({dist[j.first], j.first});
      }
    }
  }

  cout << dist[n-1];
}