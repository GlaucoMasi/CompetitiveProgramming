#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll ans = 0;
int n, k, th = 10;
vector<vector<int>> g;
vector<int> depth, logs;
vector<map<int, int>> maps;
vector<vector<pair<int, int>>> table;
vector<pair<int, int>> ord, idx;

void f(int i, int p){
  if(p != -1) depth[i] = depth[p]+1;
  ord.push_back({depth[i], i});
  for(auto j : g[i]) if(j != p) f(j, i);
  ord.push_back({depth[i], i});
}

void init() {
  int t = 2, j = 0; logs.push_back(-1);
  for(int i = 1; i <= 2*n; i++){
    if(t == i){
      t *= 2;
      j++;
    }

    logs.push_back(j);
  }

  table.push_back(ord);
  for(int j = 1; j <= logs.back(); j++){
    vector<pair<int, int>> next(2*n);
    for(int i = 0; i < 2*n; i++){
      if(i+(1<<(j-1)) < 2*n) next[i] = min(table.back()[i], table.back()[i+(1<<(j-1))]);
      else next[i] = table.back()[i];
    }
    table.push_back(next);
  }
}

int lca(int a, int b){
  if(depth[a] > depth[b]) swap(a, b);

  if(idx[a].first <= idx[b].first && idx[a].second >= idx[b].second) return a;

  if(idx[a].second > idx[b].first) swap(a, b);
  a = idx[a].second; b = idx[b].first;

  auto t = min(table[logs[b-a+1]][a], table[logs[b-a+1]][b-(1<<logs[b-a+1])+1]);
  return t.second;
}

int dist(int a, int b){
  int t = lca(a, b);
  return depth[a]+depth[b]-2*depth[t];
}

void sl(int i, int p){
  maps[i][depth[i]-i*k] = 1;
  
  for(auto j : g[i]){
    if(j == p) continue;

    sl(j, i);

    if(maps[j].size() > maps[i].size()) swap(maps[i], maps[j]);

    for(auto [a, b] : maps[j]) if(maps[i].count(2*depth[i]-a)) ans += b*maps[i][2*depth[i]-a];
    for(auto [a, b] : maps[j]) maps[i][a] += b;
  }
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  cin >> n;
  g.resize(n);
  depth.resize(n);
  maps.resize(n);
  idx.resize(n, {-1, -1});

  for(int i = 0; i < n-1; i++){
    int a, b; cin >> a >> b;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  f(0, -1);
  for(int i = 0; i < 2*n; i++){
    if(idx[ord[i].second].first == -1) idx[ord[i].second].first = i;
    else idx[ord[i].second].second = i;
  }

  init();

  for(int k = 1; k <= th; k++){
    ::k = k;
    maps = vector<map<int, int>>(n);
    sl(0, -1);
  }

  for(int i = 0; i <= n/th; i++) for(int j = i+1; j <= n/th; j++){
    int d = dist(i, j);
    ans += (!(d%(i+j)) && d/(i+j) > th);
  }

  cout << ans;
}