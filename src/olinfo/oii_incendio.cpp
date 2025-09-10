#include <bits/stdc++.h>
using namespace std;

int alzati(int n, int m, int X[], int Y[]){
  int ans = 2e9;
  vector<pair<int, int>> v(m);
  vector<int> dist(m, 2e9);
  vector<bool> prop(m, 0);
  
  for(int i = 0; i < m; i++){
    v[i] = {X[i], Y[i]};
    dist[i] = min(v[i].first, n-1-v[i].second);
  }

  while(1) {
    pair<int, int> next = {2e9, -1};
    for(int i = 0; i < m; i++) if(!prop[i]) next = min(next, {dist[i], i});

    if(next.second == -1) break;
    
    int node = next.second;
    prop[node] = 1;

    ans = min({ans, max(dist[node], n-1-v[node].first), max(dist[node], v[node].second)});

    for(int i = 0; i < m; i++){
      int d = (max(0, abs(v[node].first-v[i].first)-1))/2 + (max(0, abs(v[node].second-v[i].second)-1))/2 + min(1, (max(0, abs(v[node].first-v[i].first)-1))%2 + (max(0, abs(v[node].second-v[i].second)-1))%2);
      if(dist[i] > max(dist[node], d)) dist[i] = max(dist[node], d);
    }
  }

  return ans-1;
}