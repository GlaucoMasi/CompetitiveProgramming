#include <bits/stdc++.h>
using namespace std;

void mincammino(int n, int m, vector<int> a, vector<int> b, vector<int> c, vector<long long>& dist) {
  fill(dist.begin(), dist.end(), 2e18);

  vector<vector<pair<int, long long>>> g(n);
  for(int i = 0; i < m; i++) g[a[i]].push_back({b[i], c[i]});

  vector<bool> prop(n);
  priority_queue<pair<long long, int>> pq;

  dist[0] = 0; pq.push({0, 0});
  while(!pq.empty()){
    int i = pq.top().second; pq.pop();

    if(prop[i]) continue;
    prop[i] = 1;

    for(auto [j, l] : g[i]){
      if(dist[j] > dist[i]+l){
        dist[j] = dist[i]+l;
        pq.push({-dist[j], j});
      }
    }
  }

  for(auto &i : dist) if(i == 2e18) i = -1;
}