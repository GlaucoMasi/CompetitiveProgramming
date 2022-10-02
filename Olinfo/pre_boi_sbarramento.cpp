#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

vector<vector<pair<int, pair<int, int>>>> g;

long long fuggi(int N, int M, vector <int> A, vector <int> B, vector
<int> T, vector <int> R){
  g.resize(N);
  for(int i = 0; i < M; i++){
    g[B[i]].push_back({A[i], {T[i], R[i]}});
  }

  priority_queue<pair<long long, pair<int, bool>>, vector<pair<long long, pair<int, bool>>>, greater<pair<long long, pair<int, bool>>>> pq;
  vector<long long> dist(N, 1e18);
  vector<bool> vis(N, 0), red(N, 0);
  dist[N-1] = 0;
  pq.push({0, {N-1, 0}});

  while(!pq.empty()){
    auto curr = pq.top(); pq.pop();
    
    if(vis[curr.second.first]) continue;

    if(!curr.second.second){
      vis[curr.second.first] = 1;
      
      if(red[curr.second.first]){
        dist[curr.second.first]--;
        red[curr.second.first] = 0;
      }
    }else{
      red[curr.second.first] = 1;
      continue;
    }

    for(auto i : g[curr.second.first]){
      long long d = dist[curr.second.first] + i.second.first;

      if(i.second.second == 0){
        if(dist[i.first] > d){
          dist[i.first] = d;
          pq.push({d, {i.first, 0}});
        }
      }else{
        if(dist[i.first] > d){
          pq.push({d, {i.first, 1}});
        }
      }
    }
  }

  return dist[0];
}
