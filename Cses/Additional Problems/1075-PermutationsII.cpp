#include <bits/stdc++.h>
using namespace std;

static constexpr int mod = 1e9+7;

int main() {
  int n; cin >> n;
  vector<vector<array<long long, 3>>> dp(n, vector<array<long long, 3>>(n+2));
  dp[0][1][0] = 1;
  for(int i = 1; i < n; i++){
    for(int j = 1; j <= i+1; j++){
      dp[i][j][0] = (dp[i-1][j-1][0] + dp[i-1][j-1][1] + dp[i-1][j-1][2])%mod;
      dp[i][j][1] = (dp[i-1][j][0]*2*(j-1) + dp[i-1][j][1]*(2*j-1) + dp[i-1][j][2]*2*j)%mod;
      dp[i][j][2] = (dp[i-1][j+1][0]*j*(j-1) + dp[i-1][j+1][1]*j*j + dp[i-1][j+1][2]*j*(j+1))%mod;
    }
  }

  cout << (dp[n-1][1][0]+dp[n-1][1][1]+dp[n-1][1][2])%mod;
}