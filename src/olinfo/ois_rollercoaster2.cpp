#include <bits/stdc++.h>
using namespace std;

struct node{
  int high = 1e9, low = 1e9, fromup = 1e9, fromdown = 1e9;
};

int main() {
  int n; cin >> n;
  vector<int> v(n); for(auto &i : v) cin >> i;
  vector<vector<node>> dp(n, vector<node>(2002));
  
  for(int i = 0; i < 2002; i++) dp[0][i].high = dp[0][i].low = (v[0]-i)*(v[0]-i);

  dp[0][0].fromdown = dp[0][0].low;
  for(int i = 1; i < 2002; i++) dp[0][i].fromdown = min(dp[0][i-1].fromdown, dp[0][i].low);

  dp[0][2001].fromup = dp[0][2001].high;
  for(int i = 2000; i >= 0; i--) dp[0][i].fromup = min(dp[0][i+1].fromup, dp[0][i].high);

  for(int i = 1; i < n; i++){
    for(int j = 0; j < 2002; j++){
      int cost = (v[i]-j)*(v[i]-j);

      if(j != 0) dp[i][j].high = dp[i-1][j-1].fromdown+cost;
      if(j != 2001) dp[i][j].low = dp[i-1][j+1].fromup+cost;

      if(j != 0) dp[i][j].fromdown = min(dp[i][j-1].fromdown, dp[i][j].low);
      else dp[i][j].fromdown = dp[i][j].low;
    }

    dp[i][2001].fromup = dp[i][2001].high;
    for(int j = 2000; j >= 0; j--) dp[i][j].fromup = min(dp[i][j+1].fromup, dp[i][j].high);
  }

  int ans = 1e9;
  for(auto j : dp[n-1]) ans = min({ans, j.high, j.low});
  cout << ans;
}