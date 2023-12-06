#include <bits/stdc++.h>
using namespace std;

int n; long long t = 0;
vector<vector<int>> g;
vector<long long> sz;
pair<long long, int> curr = {1e18, -1};

void dfs(int i, int fat){
  long long down = 0;

  for(auto j : g[i]){
    if(j == fat) continue;

    dfs(j, i);
    sz[i] += sz[j];
    down = max(down, sz[j]);
  }

  curr = min(curr, {max(t - sz[i], down), i});
}

int LocateCentre(int N, int* c, int* a, int* b){
  n = N;
  g.resize(n); sz = vector<long long>(n);

  for(int i = 0; i < n; i++){
    sz[i] = c[i];
    t += c[i];
  }

  for(int i = 0; i < n-1; i++){
    g[a[i]].push_back(b[i]);
    g[b[i]].push_back(a[i]);
  }

  dfs(0, -1);
  return curr.second;
}