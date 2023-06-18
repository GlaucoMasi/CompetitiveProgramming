#include <bits/stdc++.h>
using namespace std;

int contentezza(int n, int v[]){
  vector<vector<pair<int, int>>> dp(2, vector<pair<int, int>>(n, {-1, -1}));

  for(int l = n-1; l >= 0; l--){
    for(int r = l; r < n; r++){
      if(l == r) dp[1][r] = {v[l], 0};
      else{
        if(l < n-1) dp[1][r] = {v[l] + dp[0][r].second, dp[0][r].first};
        if(r > 0) dp[1][r] = max(dp[1][r], {v[r] + dp[1][r-1].second, dp[1][r-1].first});
      }
    }
    
    dp[0] = dp[1];
  }

  return dp[0][n-1].first;
}