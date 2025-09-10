#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> g;
vector<int> dist;

int first, second;
pair<int, int> third;

void f1(int i, int fat, int d){
  dist[i] = d;

  for(auto j : g[i]){
    if(j == fat) continue;

    f1(j, i, d+1);
  }
}

void f2(int i, int fat, int d){
  if(third.second < d + dist[i]){
    third.first = i;
    third.second = d + dist[i];
  }

  for(auto j : g[i]){
    if(j == fat) continue;

    f2(j, i, d+1);
  }
}

int build(int N, vector<int> A, vector<int> B){
  g.resize(N);
  dist.resize(N);

  for(int i = 0; i < N-1; i++){
    g[A[i]].push_back(B[i]);
    g[B[i]].push_back(A[i]);
  }

  f1(0, -1, 0);
  first = max_element(dist.begin(), dist.end()) - dist.begin();

  f1(first, -1, 0);
  second = max_element(dist.begin(), dist.end()) - dist.begin();

  third.second = 0;
  f2(second, -1, 0);

  return dist[second] + third.second;
}