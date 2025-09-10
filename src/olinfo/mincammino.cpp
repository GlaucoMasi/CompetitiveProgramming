#include <bits/stdc++.h>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

vector<vector<pair<int, int>>> g;
vector<int> d;
vector<bool> vis;

void mincammino(int N, int M, vector<int> X, vector<int> Y, vector<int>
P, vector<int>& D){
  g.resize(N);
  d.resize(N, -1);
  vis.resize(N, 0);

  for(int i = 0; i < M; i++){
    int a = X[i], b = Y[i], c = P[i];

    g[a].push_back({b, c});
  }

  d[0] = 0;
  priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
  q.push({0, 0});

  while(!q.empty()){
    auto curr = q.top();
    q.pop();
    int nodo, dist;
    tie(dist, nodo) = curr;
    
    if(vis[nodo]) continue;
    vis[nodo] = 1;

    for(auto e : g[nodo]){
      if(d[e.first] > dist + e.second || d[e.first] == -1){
        d[e.first] = dist + e.second;
        q.push({d[e.first], e.first});
      }
    }
  }

  D = d;
  return;
}