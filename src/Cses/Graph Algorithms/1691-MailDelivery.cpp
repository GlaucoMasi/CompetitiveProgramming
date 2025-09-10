#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int n, m;
vector<int> path;
vector<bool> used;
vector<vector<pair<int, int>>> g;

void f(int i){
  while(!g[i].empty()){
    auto [j, idx] = g[i].back();
    g[i].pop_back();
    
    if(!used[idx]){
      used[idx] = 1;
      f(j);
    }
  }

  path.push_back(i);
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  cin >> n >> m;
  used.resize(m);
  g.resize(n);

  for(int i = 0; i < m; i++){
    int a, b; cin >> a >> b;
    g[--a].push_back({--b, i});
    g[b].push_back({a, i});
  }

  for(auto i : g) if(i.size()%2){
    cout << "IMPOSSIBLE";
    return 0;
  }

  f(0);
  if(path.size() != m+1) cout << "IMPOSSIBLE";
  else for(int i = m; i >= 0; i--) cout << path[i]+1 << " ";
}