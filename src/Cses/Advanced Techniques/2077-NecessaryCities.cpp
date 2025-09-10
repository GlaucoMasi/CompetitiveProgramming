#include <bits/stdc++.h>
using namespace std;

int t = 1;
int n, m;
vector<vector<int>> g;
vector<int> enter, low, ans;

int f(int i, int p){
  low[i] = enter[i] = t++;
  int children = 0;

  bool added = 0;
  for(auto j : g[i]){
    if(j == p) continue;

    if(!enter[j]){
      f(j, i);
      children++;

      if(enter[i] <= low[j] && !added && i != 0){
        ans.push_back(i+1);
        added = 1;
      }

      low[i] = min(low[i], low[j]);
    }else low[i] = min(low[i], enter[j]);
  }

  return children;
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

  if(f(0, -1) != 1) ans.push_back(1);

  cout << ans.size() << endl;
  for(auto i : ans) cout << i << " ";
}