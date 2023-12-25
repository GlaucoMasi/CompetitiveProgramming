#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
  int r, c; fin >> r >> c;
  vector<string> v(r);
  for(auto &i : v) fin >> i;

  vector<vector<int>> dp(r, vector<int>(c)); dp[0][0] = 1;

  for(int i = 0; i < r; i++){
    for(int j = 0; j < c; j++){
      if(dp[i][j]) continue;
      if(v[i][j] == '+'){
        dp[i][j] = 0;
        continue;
      }
      
      dp[i][j] = 0;
      if(i-1 >= 0) dp[i][j] += dp[i-1][j];
      if(j-1 >= 0) dp[i][j] += dp[i][j-1];
    }
  }

  fout << dp[r-1][c-1];
}