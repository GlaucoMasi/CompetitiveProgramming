#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  long long ans = 0;

  vector<long long> p10(12); p10[0] = 1;
  for(int i = 1; i < 12; i++) p10[i] = p10[i-1] * 10;
  
  while(cin >> s) {
    vector<vector<long long>> dp(s.size(), vector<long long>(12, -1e18));
    dp[s.size()-1][0] = s.back() - '0';

    for(int i = s.size()-2; i >= 0; i--) {
      dp[i][0] = max(dp[i+1][0], (long long)s[i] - '0');
      for(int j = 1; j < 12; j++) dp[i][j] = max(dp[i+1][j], dp[i+1][j-1] + p10[j] * (s[i] - '0'));
    }

    ans += dp[0][11];
  }

  cout << ans;
}