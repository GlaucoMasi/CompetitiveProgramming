#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int Gira(int n, int *data){
  vector<int> dp(n+1, 1e9), v(n+1);
  for(int i = 1; i <= n; i++) v[i] = v[i-1]+data[i-1];

  auto sum = [&](int l, int r){
    return v[r]-v[l-1];
  };

  dp[0] = 0;
  for(int i = 2; i <= n; i += 2)
    for(int j = 0; j < i; j += 2)
      dp[i] = min(dp[i], dp[j] + sum(j+1, (i+j)/2) + (i-j)/2 - sum((i+j)/2+1, i));

  return dp[n];
}