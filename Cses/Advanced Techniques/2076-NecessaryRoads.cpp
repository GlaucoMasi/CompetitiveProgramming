#include <bits/stdc++.h>
using namespace std;

int t = 1;
int n, m;
vector<vector<int>> g;
vector<int> enter, low; 
vector<pair<int, int>> ans;

void f(int i, int p){
  low[i] = enter[i] = t++;

  for(auto j : g[i]){
    if(j == p) continue;

    if(!enter[j]){
      f(j, i);

      if(enter[i] < low[j]) ans.push_back({i+1, j+1});

      low[i] = min(low[i], low[j]);
    }else low[i] = min(low[i], enter[j]);
  }
}

int main() {
  cin >> n >> m;
  g.resize(n);
  enter.resize(n);
  low.resize(n);

  int a, b;
  for(int i = 0; i < m; i++){
    cin >> a >> b; a--; b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  f(0, -1);

  cout << ans.size() << endl;
  for(auto i : ans) cout << i.first << " " << i.second << endl;
}