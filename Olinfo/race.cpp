#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int n, m;
vector<vector<pair<int, int>>> g, inv;

vector<int> f(int start){
  vector<int> ans(n, 1e9);
  vector<bool> prop(n);
  priority_queue<pair<int, int>> pq;

  ans[start] = 0;
  pq.push({0, start});
  while(!pq.empty()){
    int node = pq.top().second; pq.pop();

    if(prop[node]) continue;
    prop[node] = 1;

    for(auto i : g[node]){
      if(max(ans[node], i.second) < ans[i.first]){
        ans[i.first] = max(ans[node], i.second);
        pq.push({-ans[i.first], i.first});
      }
    }
  }

  return ans;
}

int main() {
  fin >> n >> m;
  g.resize(n); inv.resize(n);

  for(int i = 0; i < m; i++){
    int a, b, c; fin >> a >> b >> c;
    a--; b--;

    g[a].push_back({b, c});
    inv[b].push_back({a, c});
  }

  vector<int> top = f(0);

  swap(g, inv);
  vector<int> down = f(n-1);
  swap(g, inv);

  int ans = 2e9;
  for(int i = 0; i < n; i++){
    for(auto j : g[i]) ans = min(ans, max(top[i], down[j.first]));
  }

  fout << ans;
}