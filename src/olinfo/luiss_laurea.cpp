#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
  int n; fin >> n;
  vector<vector<int>> v(4, vector<int>(3));
  for(int i = 0; i < 4; i++) fin >> v[i][0] >> v[i][1];
  v[0][2] = 2; v[1][2] = 4; v[2][2] = 5; v[3][2] = 7;

  int tot = 1;
  for(int i = 0; i < 4; i++) tot += v[i][0]*v[i][2];

  vector<int> dp(tot, 1e9); dp[0] = 0;
  for(int i = 0; i < 4; i++){
    for(int j = 0; j < v[i][0]; j++){
      for(int k = tot-1; k-v[i][2] >= 0; k--) dp[k] = min(dp[k], dp[k-v[i][2]]+v[i][1]);
    }
  }

  int ans = 1e9;
  for(int i = n; i < tot; i++) ans = min(ans, dp[i]);
  fout << ans;
}