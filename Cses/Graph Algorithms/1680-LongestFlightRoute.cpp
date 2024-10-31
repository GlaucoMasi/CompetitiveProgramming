#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int n, m;
vector<vector<int>> g;
vector<int> ord;
vector<bool> vis;

void f(int i){
  vis[i] = 1;
  for(auto j : g[i]) if(!vis[j]) f(j);
  ord.push_back(i);
}

int main() {
  cin >> n >> m;
  g.resize(n);
  vis.resize(n);

  for(int i = 0; i < m; i++){
    int a, b; cin >> a >> b;
    g[--a].push_back(--b);
  }

  f(0);  
  if(!vis[n-1]){
    cout << "IMPOSSIBLE";
    return 0;
  }

  vector<pair<int, int>> dp(n, {-1e9, -1}); dp[n-1] = {1, -1};
  for(auto i : ord) for(auto j : g[i]) dp[i] = max(dp[i], {dp[j].first+1, j});

  int i = 0;
  cout << dp[0].first << '\n' << 1 << " ";
  do{
    i = dp[i].second;
    cout << i+1 << " ";
  }while(i != n-1);
}