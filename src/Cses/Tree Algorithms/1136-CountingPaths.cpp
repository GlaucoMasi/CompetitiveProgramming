#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> depth;
vector<vector<int>> g;
vector<pair<int, int>> tour;

int k = 25;
vector<vector<pair<int, int>>> sparse;
vector<pair<int, int>> idx;
vector<int> logs;

vector<int> start, fat;

void f(int i, int p){
  if(p != -1) depth[i] = depth[p]+1;
  tour.push_back({depth[i], i});
  fat[i] = p;

  for(auto j : g[i]){
    if(j == p) continue;
    f(j, i);
    tour.push_back({depth[i], i});
  }
}

void cum(int i){
  for(auto j : g[i]){
    if(j == fat[i]) continue;
    cum(j);
    start[i] += start[j];
  }
}

int main() {
  cin >> n >> m;
  g.resize(n);
  depth.resize(n);
  fat.resize(n);

  for(int i = 0; i < n-1; i++){
    int a, b; cin >> a >> b;
    g[--a].push_back(--b);
    g[b].push_back(a);
  }

  f(0, -1);

  idx.resize(n, {-1, -1});
  for(int i = 0; i < tour.size(); i++){
    if(idx[tour[i].second].first == -1) idx[tour[i].second].first = i;
    idx[tour[i].second].second = i;
  }

  sparse.push_back(tour);
  for(int i = 0; i < k-1; i++){
    vector<pair<int, int>> next;
    for(int j = 0; j < tour.size(); j++) next.push_back(min(sparse.back()[j], sparse.back()[min((int)tour.size()-1, j+(1<<i))]));
    sparse.push_back(next);
  }

  logs.resize(tour.size()+5); logs[1] = 0;
  for(int i = 2; i < logs.size(); i++) logs[i] = logs[i/2]+1;

  start.resize(n, 0);
  for(int i = 0; i < m; i++){
    int a, b; cin >> a >> b; a--; b--;
    int idx1 = idx[a].first, idx2 = idx[b].second;
    if(idx1 > idx2) swap(idx1, idx2);
    int sz = logs[idx2-idx1+1];
    auto t = min(sparse[sz][idx1], sparse[sz][max(0, idx2-(1<<sz)+1)]);

    start[t.second]--;
    start[a]++; start[b]++;
    if(t.second) start[fat[t.second]]--;
  }

  cum(0);
  for(auto i : start) cout << i << " ";
}