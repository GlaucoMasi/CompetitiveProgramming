#include <bits/stdc++.h>
using namespace std;

int mod = 1e9+7;

long long exp(long long a, int b){
  if(b == 0) return 1;
  if(b == 1) return a;


  long long ans = exp(a, b/2);
  ans = (ans*ans)%mod;
  if(b%2) ans = (ans*a)%mod;
  return ans;
}

int main() {
  int n, m; cin >> n >> m;

  vector<long long> fact(n+m); fact[0] = 1;
  for(int i = 1; i < n+m; i++) fact[i] = (fact[i-1]*i)%mod;

  cout << (((fact[n+m-1]*exp(fact[n-1], mod-2))%mod)*exp(fact[m], mod-2))%mod;
}