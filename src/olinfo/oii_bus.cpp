#include <bits/stdc++.h>
using namespace std;

int pianifica(int n, int l, vector<vector<int>> f){
  vector<vector<pair<int, int>>> nodi(n);
  vector<vector<int>> dist(l);

  for(int i = 0; i < l; i++){
    dist[i].resize(f[i].size(), 1e9);

    for(int j = 0; j < f[i].size(); j++) nodi[f[i][j]].push_back({i, j});
  }

  deque<pair<int, int>> dq;
  vector<bool> prop(n);

  for(auto [linea, idx] : nodi[0]){
    dq.push_back({linea, idx});
    dist[linea][idx] = 0;
  }

  int ans = 1e9;

  while(!dq.empty()){
    auto [linea, idx] = dq.front(); dq.pop_front();
    int x = f[linea][idx];

    if(x == n-1) ans = min(ans, dist[linea][idx]);

    if(idx+1 < f[linea].size() && dist[linea][idx] < dist[linea][idx+1]){
      dist[linea][idx+1] = dist[linea][idx];
      dq.push_front({linea, idx+1});
    }

    if(!prop[x]){
      prop[x] = 1;

      for(auto [newl, newi] : nodi[x]){
        if(dist[newl][newi] > dist[linea][idx]+1){
          dist[newl][newi] = dist[linea][idx]+1;
          dq.push_back({newl, newi});
        }
      }
    }
  }

  if(ans == 1e9) return -1;
  else return ans;
}