#include <bits/stdc++.h>
using namespace std;

long long ans = 0;
int n, mod = 1e9+7;
vector<long long> v;

long long exp(int a, int b){
  if(b == 0) return 1;

  long long ans = exp(a, b/2);
  ans = (ans*ans)%mod;

  if(b%2) ans = (ans*a)%mod;
  return ans;
}

int main() {
  cin >> n;
  v.resize(n);
  v[0] = v[1] = 1;

  for(int i = 2; i < n; i++) v[i] = ((v[i-1]*2*(2*i-1))%mod)*exp(i+1, mod-2)%mod;
  for(int i = 0; i < n/2; i++) ans = (ans+(v[i]*v[n-i-1])%mod)%mod;

  cout << ans;
}