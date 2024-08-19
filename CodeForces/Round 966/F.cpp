#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, k;
  cin >> n >> k;

  vector<pair<int, int>> v(n);
  for(auto &i : v) cin >> i.first >> i.second;

  vector<vector<int>> dp(n+1, vector<int>(k+1, 1e9)); dp[0][0] = 0;
  for(int i = 0; i < n; i++){
    auto [a, b] = v[i];
    int cost = 0;

    dp[i+1] = dp[i];
    for(int inc = 1; a+b; inc++){
      if(a <= b) cost += a, b--;
      else cost += b, a--;

      for(int j = 0; j+inc <= k; j++) dp[i+1][j+inc] = min(dp[i+1][j+inc], dp[i][j]+cost);
    }
  }

  cout << (dp[n][k] != 1e9 ? dp[n][k] : -1) << '\n';
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int t = 1;
  cin >> t;
  while(t--) solve();
}