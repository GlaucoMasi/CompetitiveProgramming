#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  vector<pair<int, int>> dir = {
    {0, 1},
    {0, -1},
    {1, 0},
    {-1, 0}
  };

  int k; cin >> k;
  vector<vector<long double>> ans(8, vector<long double>(8, 1));

  auto ok = [&](int x, int y){ return (x >= 0 && y >= 0 && x < 8 && y < 8); };
  
  auto calc = [&](int x, int y){
    vector<vector<long double>> dp(8, vector<long double>(8)); dp[x][y] = 1;
    for(int l = 0; l < k; l++){
      vector<vector<long double>> t(8, vector<long double>(8));
      for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
          long double moves = 0;
          for(auto [a, b] : dir) if(ok(i+a, j+b)) moves++;
          for(auto [a, b] : dir) if(ok(i+a, j+b)) t[i+a][j+b] += dp[i][j]/moves;
        }
      }

      dp = t;
    }

    for(int i = 0; i < 8; i++) for(int j = 0; j < 8; j++) ans[i][j] *= (1-dp[i][j]);
  };

  for(int i = 0; i < 8; i++) for(int j = 0; j < 8; j++) calc(i, j);
  
  long double tot = 0;
  for(auto i : ans) for(auto j : i) tot += j;
  tot *= 1e6;
  double integ, fract = modf(tot, &integ);

  if(fract == 0.5){
    if(((long long)integ%10)%2) integ++;
  }else integ = round(tot);

  integ /= 1e6;
  cout << std::setprecision(6) << std::fixed << integ;
}