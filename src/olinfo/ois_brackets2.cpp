#include <bits/stdc++.h>
using namespace std;

int main() {
  int n; cin >> n;
  vector<int> v(n);
  for(auto &i : v) cin >> i;

  vector<vector<int>> dp(n, vector<int>(50001, -1));
  dp[0][v[0]] = 1;
  for(int i = 1; i < n; i++){
    for(int j = 0; j < 50001; j++){
      if(dp[i-1][j] == -1) continue;

      int aperte = j + v[i], chiuse = j - v[i];
      dp[i][aperte] = 1;
      if(chiuse >= 0) dp[i][chiuse] = 2;
    }
  }

  if(dp[n-1][0] == -1){
    cout << -1;
    return 0;
  }

  string ans = ""; int num = 0;
  for(int i = n-1; i >= 0; i--){
    if(dp[i][num] == 1){
      for(int t = 0; t < v[i]; t++) ans += '(';
      num -= v[i];
    }else{
      for(int t = 0; t < v[i]; t++) ans += ')';
      num += v[i];
    }
  }

  for(int j = ans.size()-1; j >= 0; j--) cout << ans[j];
}