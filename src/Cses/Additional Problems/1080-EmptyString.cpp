#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int n, mod = 1e9+7;
vector<long long> fact;

long long exp(long long a, int b){
  if(b == 0) return 1;
  if(b == 1) return a;

  long long ans = exp(a, b/2);
  ans = (ans*ans)%mod;
  if(b%2) ans = (ans*a)%mod;

  return ans;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  string s; cin >> s;

  n = s.size();
  fact.resize(n+1); fact[0] = 1;
  for(long long i = 1; i <= n; i++) fact[i] = (fact[i-1]*i)%mod;

  vector<vector<long long>> bin(n+1, vector<long long>(n+1));
  for(int a = 0; a <= n; a++) for(int b = 0; b <= n; b++) bin[a][b] = (((fact[a+b]*exp(fact[a], mod-2))%mod)*exp(fact[b], mod-2))%mod;

  vector<vector<long long>> dp(n, vector<long long>(n));
  for(int i = 0; i+2 <= n; i++) dp[i][i+1] = (s[i] == s[i+1]);

  auto get = [&](int l, int r){ return (l <= r ? dp[l][r] : 1); };

  for(int len = 4; len <= n; len += 2){
    for(int l = 0; l+len <= n; l++){
      int r = l+len-1;
      for(int k = l+1; k <= r; k += 2) if(s[l] == s[k]) dp[l][r] = (dp[l][r] + ((get(l+1, k-1)*((get(k+1, r)*bin[(k-l+1)/2][(r-k)/2])%mod))%mod))%mod;
    }
  }

  cout << dp[0][n-1];
}