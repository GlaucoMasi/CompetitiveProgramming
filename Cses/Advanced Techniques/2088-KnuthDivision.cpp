#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  int n; cin >> n;
  vector<long long> v(n);
  for(auto &i : v) cin >> i;
  for(int i = 1; i < n; i++) v[i] += v[i-1];

  auto cost = [&](int l, int r){
    return v[r] - (l ? v[l-1] : 0);
  };

  vector<vector<int>> best(n, vector<int>(n));
  vector<vector<long long>> dp(n, vector<long long>(n, 1e18));
  for(int i = 0; i < n; i++) dp[i][i] = 0;
  for(int i = 0; i < n; i++) best[i][i] = i;

  for(int l = 2; l <= n; l++){
    for(int i = 0; i+l <= n; i++){
      int j = i+l-1;
      long long add = cost(i, j);
      for(int k = best[i][j-1]; k <= min(j-1, best[i+1][j]); k++) if(dp[i][k] + dp[k+1][j] + add < dp[i][j]){
        dp[i][j] = dp[i][k]+dp[k+1][j]+add;
        best[i][j] = k;
      }
    }
  }

  cout << dp[0][n-1];
}