#include <bits/stdc++.h>
using namespace std;

void dfs(int i, vector<vector<int>> const& g, vector<int> &ord, vector<int> &vis) {
  vis[i] = true;
  for(auto j : g[i]) if(!vis[j]) dfs(j, g, ord, vis);
  ord.push_back(i);
}

vector<vector<int>> condG;
vector<long long> condC, memo;
void dp(int i) {
  memo[i] = -1e18;
  for(auto j : condG[i]) {
    if(memo[j] == -1) dp(j);
    memo[i] = max(memo[i], memo[j]);
  }
  memo[i] += condC[i];
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m; cin >> n >> m;
  vector<vector<int>> g(n), inv(n);
  vector<int> c(n), vis(n), roots(n);
  for(auto &i : c) cin >> i;
  for(int i = 0; i < m; i++) {
    int a, b; cin >> a >> b;
    g[a].push_back(b);
    inv[b].push_back(a);
  }

  vector<int> ord;
  for(int i = 0; i < n; i++) if(!vis[i]) dfs(i, g, ord, vis);

  int cnt = 0;
  vis.assign(n, false);
  for(int i = n-1; i >= 0; i--) {
    int u = ord[i];
    if(vis[u]) continue;

    vector<int> comp;
    dfs(u, inv, comp, vis);

    int root = cnt++;
    condC.push_back(0);
    memo.push_back(-1);
    
    for(auto j : comp) {
      roots[j] = root;
      condC.back() += c[j];
    }
  }

  condG = vector<vector<int>>(cnt);
  for(int i = 0; i < n; i++) for(auto j : g[i]) if(roots[i] != roots[j]) condG[roots[i]].push_back(roots[j]);
  
  memo[roots[n-1]] = condC[roots[n-1]];
  for(int i = 0; i < cnt; i++) if(memo[i] == -1) dp(i);
  cout << memo[roots[0]];
}