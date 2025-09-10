#include <bits/stdc++.h>
using namespace std;

long long plan(int n, int m, int k, vector<int> a, vector<int> b, vector<int> l, vector<int> c, vector<int> t){
  vector<vector<array<int, 3>>> g(n);
  vector<map<int, vector<array<int, 2>>>> spec(n);

  vector<map<int, long long>> dist(n);

  for(int i = 0; i < m; i++){
    g[a[i]].push_back({b[i], l[i], c[i]});
    g[b[i]].push_back({a[i], l[i], c[i]});

    spec[a[i]][c[i]].push_back({b[i], l[i]});
    spec[b[i]][c[i]].push_back({a[i], l[i]});

    dist[a[i]][c[i]] = 1e18;
    dist[b[i]][c[i]] = 1e18;
  }

  vector<bool> prop(n);
  priority_queue<pair<long long, pair<int, int>>> pq;
  dist[0][k] = 0; pq.push({0, {0, k}});
  while(!pq.empty()){
    auto [i, comp] = pq.top().second; pq.pop();
    if(i == n-1) return dist[i][comp];

    for(auto [b, l] : spec[i][comp]){
      if(dist[b][comp] > dist[i][comp]+l){
        dist[b][comp] = dist[i][comp]+l;
        pq.push({-dist[b][comp], {b, comp}});
      }
    }

    if(prop[i]) continue;
    prop[i] = 1;

    for(auto [b, l, c] : g[i]){
      if(dist[b][c] > dist[i][comp]+l+t[c]){
        dist[b][c] = dist[i][comp]+l+t[c];
        pq.push({-dist[b][c], {b, c}});
      }
    }  
  }
}