#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int solve(int N, int M, int T, int* S, int* E){
  vector<vector<int>> g1(N), g2(N);
  for(int i = 0; i < M; i++){
    g1[S[i]].push_back(E[i]);
    g2[E[i]].push_back(S[i]);
  }

  priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
  pq.push({0, 0});
  vector<long long> d(N, 1e18);
  vector<vector<bool>> vis(N, vector<bool>(2, 0));

  while(!pq.empty()){
    long long dist = pq.top().first;
    int nodo = pq.top().second;
    pq.pop();

    bool marea = dist >= T;

    if(vis[nodo][marea]){
      if(nodo == N-1) break;
      else continue;
    }
    vis[nodo][marea] = 1;

    //giusto?
    int add = marea ? 1 : T-dist+1;
    for(auto i : g2[nodo]){
      if(dist+add < d[i]){
        d[i] = dist+add;
        pq.push({d[i], i});
      }
    }

    if(!marea){
      for(auto i : g1[nodo]){
        if(dist+1 < d[i]){
          d[i] = dist+1;
          pq.push({d[i], i});
        }
      }
    }
  }

  int ans = d[N-1] == 1e18 ? -1 : d[N-1];
  return ans;
}