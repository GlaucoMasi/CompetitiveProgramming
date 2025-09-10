#include <bits/stdc++.h>
using namespace std;
ofstream fout("output.txt");

vector<vector<int>> g, sparse;
vector<int> sz, fat, head, heavy, idx, depth, ord, logs;

void f(int i, int p){
  fat[i] = p;
  if(p != -1) depth[i] = depth[p]+1;

  for(auto j : g[i]){
    if(j == p) continue;
    f(j, i); sz[i] += sz[j];
    if(sz[j] > sz[heavy[i]]) heavy[i] = j;
  }
}

void hld(int i, int h, vector<int> &v){
  head[i] = h;
  idx[i] = ord.size();
  ord.push_back(v[i]);

  if(heavy[i] != v.size()) hld(heavy[i], h, v);
  for(auto j : g[i]) if(j != fat[i] && j != heavy[i]) hld(j, j, v);
}

int get(int l, int r){
  if(l >= r) return 0;
  int sz = logs[r-l];
  return max(sparse[sz][l], sparse[sz][max(0, r-(1<<sz))]);
}

vector<int> raccogli(int n, int q, vector<int> &a, vector<int> &b, vector<int> &c, vector<int> &l, vector<int> &t){
  g.resize(n);
  for(int i = 0; i < n-1; i++){
    g[a[i]].push_back(b[i]);
    g[b[i]].push_back(a[i]);
  }

  fat.resize(n);
  depth.resize(n);
  heavy.resize(n, n);
  sz.resize(n, 1); sz.push_back(-1);
  f(0, -1);

  idx.resize(n);
  head.resize(n);
  hld(0, 0, c);

  sparse.push_back(ord);
  for(int i = 0; i < 25; i++){
    vector<int> next;
    for(int j = 0; j < n; j++) next.push_back(max(sparse.back()[j], sparse.back()[(min(n-1, j+(1<<i)))]));
    sparse.push_back(next);
  }

  logs.resize(n); logs[1] = 0;
  for(int i = 2; i < n; i++) logs[i] = logs[i/2]+1;

  vector<int> ans;
  for(int i = 0; i < q; i++){
    int a = l[i], b = t[i];

    vector<pair<int, int>> quer;
    for(; head[a] != head[b]; b = fat[head[b]]){
      if(depth[head[a]] > depth[head[b]]) swap(a, b);
      quer.push_back({idx[head[b]], idx[b]+1});
    }

    if(depth[a] > depth[b]) swap(a, b);
    quer.push_back({idx[a], idx[b]+1});

    if(quer.empty()){
      ans.push_back(get(0, n));
      continue;
    }

    int temp;
    sort(quer.begin(), quer.end());
    temp = max(get(quer.back().second, n), get(0, quer[0].first));
    for(int i = 1; i < quer.size(); i++){
      if(quer[i-1].second >= quer[i].first){
        quer[i].second = max(quer[i].second, quer[i-1].second);
        continue;
      }

      temp = max(temp, get(quer[i-1].second, quer[i].first));
    }

    ans.push_back(temp);
  }

  return ans;
}