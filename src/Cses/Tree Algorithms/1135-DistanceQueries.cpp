#include <bits/stdc++.h>
using namespace std;

int n, q;
vector<vector<int>> g;
vector<vector<int>> sparse;
vector<int> depth, idx, logs, vals;

void f(int i, int p){
  if(p != -1) depth[i] = depth[p]+1;
  vals.push_back(depth[i]);
  idx[i] = vals.size()-1;

  for(auto j : g[i]){
    if(j == p) continue;
    f(j, i);
    vals.push_back(depth[i]);
  }
}

int main() {
  int n, q; cin >> n >> q;
  g.resize(n);
  idx.resize(n);
  depth.resize(n);

  for(int i = 0; i < n-1; i++){
    int a, b; cin >> a >> b;
    g[--a].push_back(--b);
    g[b].push_back(a);
  }

  f(0, -1);

  sparse.push_back(vals);
  for(int k = 0; k < 25; k++){
    vector<int> next;
    for(int j = 0; j < vals.size(); j++) next.push_back(min(sparse.back()[j], sparse.back()[min((int)vals.size()-1, j+(1<<k))]));
    sparse.push_back(next);
  }

  logs.resize(vals.size()); logs[1] = 0;
  for(int i = 2; i < vals.size(); i++) logs[i] = logs[i/2]+1;

  for(int i = 0; i < q; i++){
    int a, b; cin >> a >> b;
    int idx1 = idx[--a], idx2 = idx[--b];
    if(idx1 > idx2) swap(idx1, idx2);
    int sz = logs[idx2-idx1+1];
    cout << depth[a]+depth[b]-2*min(sparse[sz][idx1], sparse[sz][max(0, idx2-(1<<sz)+1)]) << '\n';
  }
}