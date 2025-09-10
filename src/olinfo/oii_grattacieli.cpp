#include <bits/stdc++.h>
using namespace std;

long long costruisci(int n, int m, vector<long long>& h, vector<int>& a, vector<int>& b, vector<int>& c){
  vector<vector<pair<int, int>>> g(n);
  for(int i = 0; i < m; i++){
    g[a[i]].push_back({b[i], c[i]});
  }

  vector<bool> prop(n);
  priority_queue<pair<long long, int>> pq;
  for(int i = 0; i < n; i++) pq.push({-h[i], i});
  while(!pq.empty()){
    int i = pq.top().second; pq.pop();

    if(prop[i]) continue;
    prop[i] = 1;

    for(auto j : g[i]){
      if(h[j.first] > h[i]+j.second){
        h[j.first] = h[i]+j.second;
        pq.push({-h[j.first], j.first});
      }
    }
  }

  long long ans = 0;
  for(auto i : h) ans += i;
  return ans;
}