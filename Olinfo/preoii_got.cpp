#include <bits/stdc++.h>
using namespace std;

int n, k, s, e, t;
vector<vector<array<int, 4>>> g;

bool test(int lim){
  vector<vector<long long>> dist(n, vector<long long>(k+1, 2e18));
  vector<vector<bool>> prop(n, vector<bool>(k+1));
  priority_queue<pair<int, pair<int, int>>> pq;

  dist[s][k] = 0;
  pq.push({0, {s, k}});
  while(!pq.empty()){
    auto [i, bigl] = pq.top().second; pq.pop();

    if(prop[i][bigl]) continue;
    prop[i][bigl] = 1;

    if(i == e) return (dist[i][bigl] <= t);

    for(auto [j, walk, bus, num] : g[i]){
      if(num <= lim && dist[j][bigl] > dist[i][bigl] + walk){
        dist[j][bigl] = dist[i][bigl] + walk;
        pq.push({-dist[j][bigl], {j, bigl}});
      }

      if(bigl && dist[j][bigl-1] > dist[i][bigl] + bus){
        dist[j][bigl-1] = dist[i][bigl] + bus;
        pq.push({-dist[j][bigl-1], {j, bigl-1}});
      }
    }
  }

  return 0;
}

int avoid_volunteers(int subtask, int n, int m, int k, int s, int e, int t, int a[], int b[], int w[], int p[], int v[]){
  ::n = n, ::k = k, ::s = s, ::e = e, ::t = t;
  g.resize(n);

  for(int i = 0; i < m; i++){
    g[a[i]].push_back({b[i], w[i], p[i], v[i]});
    g[b[i]].push_back({a[i], w[i], p[i], v[i]});
  }
  
  int worst = -1;
  for(int i = 0; i < m; i++) worst = max(worst, v[i]);
  worst += 5;

  int l = 0, r = worst;
  while(l < r-1){
    int m = l + (r-l)/2;

    if(test(m)) r = m;
    else l = m;
  }

  return (l == worst-1 ? -1 : l+1);
}