#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int n, m, k;
vector<vector<pair<int, int>>> g;
vector<int> comm, pig;

vector<long long> dijkstra(int node){
  vector<bool> vis(n);
  vector<long long> dist(n, 1e18);
  priority_queue<pair<long long, int>> pq;

  dist[node] = 0;
  pq.push({0, node});
  while(!pq.empty()){
    int i = pq.top().second; pq.pop();

    if(vis[i]) continue;
    vis[i] = 1;

    for(auto [j, l] : g[i]){
      if(dist[j] > dist[i]+l){
        dist[j] = dist[i]+l;
        pq.push({-dist[j], j});
      }
    }
  }

  return dist;
}


int main() {
  fin >> n >> m >> k;
  g.resize(n);
  comm.resize(k);
  pig.resize(k);

  for(auto &i : comm) fin >> i;
  for(auto &i : pig) fin >> i;

  for(int i = 0; i < m; i++){
    int a, b, c;
    fin >> a >> b >> c;

    g[a].push_back({b, c});
    g[b].push_back({a, c});
  }
  
  vector<vector<long long>> dist(k);
  for(int i = 0; i < k; i++) dist[i] = dijkstra(comm[i]);

  pair<long long, int> ans; ans.first = 1e18;
  for(int i = 0; i < n; i++){
    long long curr = 0;

    for(int j = 0; j < k; j++) curr += dist[j][i]*pig[j];

    if(curr < ans.first) ans = {curr, 1};
    else if(curr == ans.first) ans.second++;
  }

  fout << ans.second << '\n' << ans.first;
}