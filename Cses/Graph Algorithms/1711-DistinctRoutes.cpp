#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> g, clean;
vector<vector<int>> cap;

int flow(vector<int> &fat){
  fill(fat.begin(), fat.end(), -1); fat[0] = -2;
  queue<int> q; q.push(0);
  while(!q.empty()){
    int i = q.front(); q.pop();

    if(i == n-1) return 1;

    for(auto j : g[i]){
      if(fat[j] != -1 || !cap[i][j]) continue;
      fat[j] = i; q.push(j);
    }
  }

  return 0;
}

bool f(int i, vector<int> &path){
  path.push_back(i);

  if(i == n-1){
    cout << path.size() << '\n';
    for(int j = 0; j < path.size()-1; j++) cap[path[j]][path[j+1]]++;
    for(auto j : path) cout << j+1 << " "; cout << '\n';
    path.clear();
    return 1;
  }else for(auto j : clean[i]) if(!cap[i][j] && f(j, path)) return 1;
  
  path.pop_back();
  return 0;
}

int main() {
  cin >> n >> m;
  g.resize(n);
  cap.resize(n, vector<int>(n));

  vector<pair<int, int>> edg;
  for(int i = 0; i < m; i++){
    int a, b; cin >> a >> b;
    cap[--a][--b] = 1;
    g[a].push_back(b);
    g[b].push_back(a);
    edg.push_back({a, b});
  }

  int tot = 0;
  vector<int> fat(n);
  while(flow(fat)){
    tot++;

    int i = n-1;
    while(i != 0){
      cap[fat[i]][i]--;
      cap[i][fat[i]]++;
      i = fat[i];
    }
  }

  clean.resize(n);
  for(auto [i, j] : edg) clean[i].push_back(j);

  cout << tot << '\n';
  vector<int> path;
  while(tot--) f(0, path);
}