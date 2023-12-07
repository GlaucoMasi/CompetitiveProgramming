#include <bits/stdc++.h>
using namespace std;

#define int long long

int n, m;
vector<vector<pair<int, long long>>> g;
vector<int> prov;

int32_t main() {
  cin >> n >> m;
  g.resize(n); prov.resize(n);

  for(int i = 0; i < m; i++){
    int a, b, c; cin >> a >> b >> c;
    g[a].push_back({b, c});
    g[b].push_back({a, c});
  }

  vector<bool> prop(n);
  vector<long long> dist(n, 1e18); dist[1] = 0;
  priority_queue<pair<long long, int>> pq; pq.push({0, 1});
  while(!pq.empty()){
    int node = pq.top().second; pq.pop();

    if(prop[node]) continue;
    prop[node] = 1;

    for(auto [j, d] : g[node]){
      if(dist[j] > dist[node]+d){
        dist[j] = dist[node]+d;
        pq.push({-dist[j], j});
        prov[j] = node;
      }
    }
  }

  queue<int> q; q.push(0);
  vector<int> bef(n);
  vector<int> d(n, -1); d[0] = 1;
  while(!q.empty()){
    int node = q.front(); q.pop();
    if(node == 1) break;

    for(auto [j, t] : g[node]){
      if(d[j] == -1 && prov[node] != j){
        d[j] = d[node]+1;
        bef[j] = node;
        q.push(j);
      }
    }
  }

  if(d[1] == -1) cout << "impossible";
  else{
    cout << d[1] << " ";
    vector<int> path = {1};
    int i = 1;
    while(i != 0){
      i = bef[i];
      path.push_back(i);
    }
    for(int i = path.size()-1; i >= 0; i--) cout << path[i] << " ";
  }
}