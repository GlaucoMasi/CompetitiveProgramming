#include <bits/stdc++.h>
using namespace std;

int n, m, k;
vector<int> diff;
vector<vector<pair<int, int>>> g;
vector<vector<int>> dp;

int f(int i, int coins){
  if(dp[i][coins] != -1) return dp[i][coins];
  if(i == n-1){
    dp[i][coins] = diff[i]; int c = coins;
    while(c--) dp[i][coins] /= 2;

    return dp[i][coins];
  }

  dp[i][coins] = 2e9;
  for(auto [j, d] : g[i]){
    int here = diff[i];

    for(int used = 0; used <= coins; used++){
      int needed = f(j, coins-used+d);

      dp[i][coins] = min(dp[i][coins], max(needed, here));
      here /= 2;
    }
  }

  return dp[i][coins];
}

int main() {
  cin >> n >> m >> k;
  diff.resize(n); dp.resize(n, vector<int>(101, -1));
  for(auto &i : diff) cin >> i;

  g.resize(n);
  for(int i = 0; i < m; i++){
    int a, b, c; cin >> a >> b >> c;
    g[a].push_back({b, c});
  }

  cout << f(0, k);
}