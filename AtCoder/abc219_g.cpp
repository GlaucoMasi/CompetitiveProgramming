#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m, q; cin >> n >> m >> q;

  vector<pair<int, int>> v(n);
  vector<pair<int, int>> upd(n);
  for(int i = 0; i < n; i++){
    v[i] = {0, i};
    upd[i] = {-1, -1};
  }

  vector<vector<int>> g(n), big(n);
  for(int i = 0; i < m; i++){
    int a, b; cin >> a >> b;
    g[--a].push_back(--b);
    g[b].push_back(a);
  }

  constexpr int k = 512;
  for(int i = 0; i < n; i++) for(auto j : g[i]){
    if(g[j].size() >= k) big[i].push_back(j);
  }

  for(int i = 1; i <= q; i++){
    int x; cin >> x; x--;
    for(auto j : big[x]) v[x] = max(v[x], upd[j]);

    if(g[x].size() >= k) upd[x] = {i, v[x].second};
    else for(auto j : g[x]) v[j] = {i, v[x].second};
  }

  for(int i = 0; i < n; i++) for(auto j : big[i]) v[i] = max(v[i], upd[j]);
  for(auto i : v) cout << i.second+1 << " ";
}