#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, r, t, l;
  cin >> n >> r >> t >> l;

  vector<int> v(n+1); v[0] = 0;
  for(int i = 1; i <= n; i++) cin >> v[i];
  v.push_back(l);

  int ans = 2e9;
  vector<vector<int>> dp(n+2, vector<int>(r+1, 2e9));

  for(int i = 0; i <= r; i++) dp[0][i] = 0;

  for(int i = 1; i <= n+1; i++){
    for(int j = r; j >= 0; j--){
      if((dp[i-1][j] / t) % 2 == 0) dp[i][j] = dp[i-1][j] + (v[i]-v[i-1]);
      else dp[i][j] = (v[i]-v[i-1]) + (dp[i-1][j] / t + 1) * t;

      if(j != r && (dp[i-1][j+1] / t) % 2 == 1) dp[i][j] = min(dp[i][j], dp[i-1][j+1] + (v[i]-v[i-1]));

      if(i == n+1) ans = min(ans, dp[i][j]);
    }
  }

  cout << ans;
}