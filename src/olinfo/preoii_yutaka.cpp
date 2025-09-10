#include <bits/stdc++.h>
using namespace std;

int taglia(int n, int v[]){
  int mod = 1e9+7;
  vector<int> cum(n+1), dp(n+1);
  cum[0] = 1; dp[0] = 1;

  int lim = 0;
  unordered_map<int, int> m;
  for(int i = 1; i <= n; i++){
    if(m.count(v[i-1])) lim = max(lim, m[v[i-1]]);
    
    dp[i] = (cum[i-1] - (lim ? cum[lim-1] : 0) + mod)%mod;
    cum[i] = (cum[i-1] + dp[i])%mod;

    m[v[i-1]] = i;
  }

  return dp[n];
}