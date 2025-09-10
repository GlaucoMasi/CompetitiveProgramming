#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int Analizza(int N, int M, int W, int L,
int arco_da[], int arco_a[], int capacita[], int R, int C){
  vector<vector<pair<int, int>>> g(N);
  for(int i = 0; i < M; i++){
    g[arco_da[i]-1].push_back({arco_a[i]-1, capacita[i]});
    g[arco_a[i]-1].push_back({arco_da[i]-1, capacita[i]});
  }

  vector<pair<int, int>> minimo(N, {2e9, 2e9});
  vector<bool> vis(N, 0);
  priority_queue<pair<pair<int, int>, int>, vector<pair<pair<int, int>, int>>, greater<pair<pair<int, int>, int>>> pq;
  minimo[W-1] = {0, 2e9};
  pq.push({{0, 2e9}, W-1});
  while(!pq.empty()){
    int node = pq.top().second; pq.pop();

    if(node == L-1) break;
    if(vis[node]) continue;
    vis[node] = 1;

    for(auto j : g[node]){
      pair<int, int> s = {minimo[node].first+1, min(minimo[node].second, j.second)};

      if(minimo[j.first] > s){
        minimo[j.first] = s;
        pq.push({s, j.first});
      }
    }
  }

  return minimo[L-1].second;
}