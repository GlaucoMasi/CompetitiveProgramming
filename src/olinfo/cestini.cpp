#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> v;

int inizia(int N, int M){
  v.resize(M);

  for(int i = 0; i < N; i++) v[0].push_back(i);
  return 0;
}

void sposta(int a, int b){
  v[b].push_back(v[a].back());
  v[a].pop_back();
}

int controlla(int a, int i){
  if(v[a].size() <= i) return -1;
  return v[a][i];
}