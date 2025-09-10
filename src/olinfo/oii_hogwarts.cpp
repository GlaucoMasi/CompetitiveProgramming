#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");
#define type pair<pair<int, int>, int>

int raggiungi(int N, int M, int A[], int B[], int inizio[], int fine[]){
  vector<vector<pair<int, int>>> g(N);
  for(int i = 0; i < M; i++){
    g[A[i]].push_back({B[i], i});
    g[B[i]].push_back({A[i], i});
  }

  priority_queue<type, vector<type>, greater<type>> q;
  vector<int> d(N, 1e9);
  vector<bool> vis(N, 0);

  q.push({{0, 0}, 0});
  d[0] = 0;
  while(!q.empty()){
    int dist = q.top().first.first;
    int time = q.top().first.second;
    int node = q.top().second;
    q.pop();

    if(vis[node]){
      if(node == N-1) break;
      else continue; 
    }
    vis[node] = 1;

    for(auto i : g[node]){
      int spend = 1;
      if(inizio[i.second] > time) spend += inizio[i.second]-time;

      if(d[i.first] > dist+spend && fine[i.second] > time){
        d[i.first] = dist+spend;
        q.push({{d[i.first], time+spend}, i.first});
      }
    }
  }

  int ans = d[N-1] == 1e9 ? -1 : d[N-1];
  return ans;
}