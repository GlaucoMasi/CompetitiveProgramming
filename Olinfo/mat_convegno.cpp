#include <bits/stdc++.h>
using namespace std;

int root, tot = 0;
vector<vector<int>> g;

int f(int i){
  int ans = 0;

  for(auto j : g[i]) ans += f(j);

  tot += ans;
  return ans+1;
}

int coppie(int N, int C[]){
  g.resize(N);

  for(int i = 0; i < N; i++){
    if(C[i] == -1) root = i;
    else g[C[i]].push_back(i);
  }

  f(root);
  return tot;
}