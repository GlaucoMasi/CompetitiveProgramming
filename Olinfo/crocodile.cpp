#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

vector<vector<pair<int, int>>> g;

extern int travel_plan(int N, int M, int R[][2], int L[], int K, int P[]){
  g.resize(N);
  for(int i = 0; i < M; i++){
    g[R[i][0]].push_back({R[i][1], L[i]});
    g[R[i][1]].push_back({R[i][0], L[i]});
  }
  
  vector<int> vis(N, 0);
  vector<pair<int, int>> dist(N, {1e9, 1e9});
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

  for(int i = 0; i < K; i++){
    vis[P[i]] = 1;
    pq.push({0, P[i]});
  }

  while(!pq.empty()){
    int d = pq.top().first, node = pq.top().second;
    pq.pop();

    if(vis[node] == 0){
      vis[node] = 1;
      continue;
    }else if(vis[node] == 2) continue;

    if(node == 0) return d;
    vis[node]++;

    for(auto i : g[node]){
      if(dist[i.first].second < d+i.second) continue;
      else if(dist[i.first].first > d+i.second){
        dist[i.first].second = dist[i.first].first;
        dist[i.first].first = d+i.second;
      }else{
        dist[i.first].second = d+i.second;
      }

      pq.push({d+i.second, i.first});
    }
  }
}
