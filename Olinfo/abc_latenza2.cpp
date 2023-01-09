#include <bits/stdc++.h>
using namespace std;

long long ans = 0;
vector<vector<pair<int, int>>> g;

void dijkstra(int i, int n){
  vector<bool> vis(n);
  vector<long long> dist(n, 1e18);
  priority_queue<pair<long long, int>> pq;
  dist[i] = 0; pq.push({0, i});

  while(!pq.empty()){
    auto curr = pq.top(); pq.pop();
  
    if(vis[curr.second]) continue;
    vis[curr.second] = 1;
    ans = max(ans, -curr.first);

    for(auto j : g[curr.second]){
      if(dist[j.first] > dist[curr.second] + j.second){
        dist[j.first] = dist[curr.second] + j.second;
        pq.push({-dist[j.first], j.first});
      }
    }
  }
}

int latenza(int n, int m, int a[], int b[], int l[]){
  g.resize(n);

  for(int i = 0; i < m; i++){
    g[a[i]-1].push_back({b[i]-1, l[i]});
    g[b[i]-1].push_back({a[i]-1, l[i]});
  }

  for(int i = 0; i < n; i++) dijkstra(i, n);

  return ans;
}