#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");
 
int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
  int mod = 1e9+7;
  int n, m; cin >> n >> m;
  vector<vector<pair<int, int>>> g(n);
 
  for(int i = 0; i < m; i++){
    int a, b, c; cin >> a >> b >> c;
    g[--a].push_back({--b, c});
  }
 
  vector<bool> prop(n);
  vector<long long> dist(n, 1e18);
  vector<array<int, 3>> val(n, {0, m, 0});
  priority_queue<pair<long long, int>> pq;
 
  dist[0] = 0; val[0] = {1, 0, 0}; pq.push({0, 0});
  while(!pq.empty()){
    auto i = pq.top().second; pq.pop();
 
    if(prop[i]) continue;
    prop[i] = 1;
 
    for(auto [j, l] : g[i]){
      if(dist[i]+l < dist[j]){
        dist[j] = dist[i]+l;
        val[j][0] = val[i][0];
        val[j][1] = val[i][1]+1;
        val[j][2] = val[i][2]+1;
        pq.push({-dist[j], j});
      }else if(dist[i]+l == dist[j]){
        val[j][0] = (val[j][0]+val[i][0])%mod;
        val[j][1] = min(val[j][1], val[i][1]+1);
        val[j][2] = max(val[j][2], val[i][2]+1);
      }
    }
  }
 
  cout << dist[n-1] << " ";
  for(auto i : val[n-1]) cout << i << " ";
}