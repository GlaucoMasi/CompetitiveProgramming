#include <bits/stdc++.h>
using namespace std;

long long viaggia(int n, int m, vector<int> a, vector<int> b, vector<int> t, vector<int> v, vector<int> w){
  vector<vector<pair<int, int>>> g(n);
  for(int i = 0; i < m; i++) g[b[i]].push_back({a[i], t[i]});

  vector<bool> prop(n);
  vector<pair<int, long long>> skip(n);
  vector<long long> dist(n, 1e18);
  priority_queue<pair<long long, int>> pq;

  dist[n-1] = 0; pq.push({0, n-1});
  while(!pq.empty()){
    int i = pq.top().second; pq.pop();

    if(prop[i]) continue;
    prop[i] = 1;

    for(auto [j, l] : g[i]){
      if(dist[j] > dist[i]+l){
        dist[j] = dist[i]+l;
        skip[j] = {i, l};
        pq.push({-dist[j], j});
      }
    }
  }

  auto get = [&](auto self, int i) {
    if(v[i] != -1 || i == n-1) return make_pair(i, 0LL);
    auto temp = self(self, skip[i].first);
    skip[i].first = temp.first;
    skip[i].second += temp.second;
    return skip[i];
  };

  for(int i = 0; i < n; i++) get(get, i);

  int i = 0; long long ans = 0;
  while(i != n-1){
    if(v[i] != -1){
      int t = v[i];
      ans += w[i];
      v[i] = w[i] = -1;
      i = t;
    }else{
      get(get, i);
      ans += skip[i].second;
      i = skip[i].first;
    }
  }

  return ans;
}