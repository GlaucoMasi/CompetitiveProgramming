#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int n, m, k;
vector<vector<pair<int, int>>> g;
vector<pair<int, int>> aule;
set<int> check;

vector<int> dijkstra(int node){
  vector<bool> vis(n);
  vector<int> dist(n, 1e9);
  priority_queue<pair<int, int>> pq;

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
  aule.resize(k);

  for(int i = 0; i < k; i++){
    fin >> aule[i].first; aule[i].first--;
    check.insert(aule[i].first);
    aule[i].second = i;
  }

  for(int i = 0; i < m; i++){
    int a, b, c; fin >> a >> b >> c;
    a--; b--;

    g[a].push_back({b, c});
    g[b].push_back({a, c});
  }

  vector<vector<int>> dist(k);
  for(int i = 0; i < k; i++) dist[i] = dijkstra(aule[i].first);

  int best = 1e9;
  for(int i = 0; i < n; i++){
    if(check.count(i)) continue;

    do{
      int curr = dist[aule[0].second][i] + dist[aule[k-1].second][i];

      for(int j = 0; j < k-1; j++) curr += dist[aule[j].second][aule[j+1].first];

      best = min(best, curr);
    }while(next_permutation(aule.begin(), aule.end()));
  }

  fout << best;
}