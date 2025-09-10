#include <bits/stdc++.h>
using namespace std;

int n, idx = 1;
vector<vector<int>> c, g;

int flow(vector<int> &fat){
  fat.clear(); fat.resize(idx, -1);
  queue<pair<int, int>> q;
  q.push({1e9, 0}); fat[0] = -2;

  while(!q.empty()){
    auto [maxflow, i] = q.front(); q.pop();
    if(i == idx-1) return maxflow;

    for(auto j : g[i]){
      if(!c[i][j]) continue;
      if(fat[j] != -1) continue;

      fat[j] = i;
      q.push({min(maxflow, c[i][j]), j});
    }
  }

  return 0;
}

int main() {
  cin >> n;
  map<int, int> x, y;

  vector<pair<int, int>> v;
  for(int i = 0; i < n; i++){
    int a, b; cin >> a >> b;
    v.push_back({a, b});
    
    x[a]++;
    y[b]++;
  }

  bool ok = 0;
  for(auto i : x) ok |= (i.second%3);
  for(auto i : y) ok |= (i.second%3);
  if(ok){
    cout << "No";
    return 0;
  }

  map<int, int> compx, compy;
  for(auto i : x) compx[i.first] = idx++;
  for(auto i : y) compy[i.first] = idx++;
  
  idx++;
  g.resize(idx);
  c.resize(idx, vector<int>(idx));
  for(auto i : x){
    g[0].push_back(compx[i.first]);
    g[compx[i.first]].push_back(0);
    c[0][compx[i.first]] = i.second/3;
  }

  for(auto i : y){
    g[compy[i.first]].push_back(idx-1);
    g[idx-1].push_back(compy[i.first]);
    c[compy[i.first]][idx-1] = i.second/3;
  }

  for(auto i : v){
    g[compx[i.first]].push_back(compy[i.second]);
    g[compy[i.second]].push_back(compx[i.first]);
    c[compx[i.first]][compy[i.second]] = 1;
  }

  int t, tot = 0;
  vector<int> fat;
  while(t = flow(fat)){
    tot += t;
    int i = idx-1;
    while(i){
      c[fat[i]][i] -= t;
      c[i][fat[i]] += t;
      i = fat[i];
    }
  }

  cout << "Yes\n" << tot << '\n';
  for(auto i : v) if(!c[compx[i.first]][compy[i.second]]) cout << i.first << " " << i.second << '\n';
}