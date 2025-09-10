#include <bits/stdc++.h>
using namespace std;

int mod = 1e9+7;
vector<long long> fact(2e5+1);

long long exp(long long a, int b){
  if(b == 0) return 1;
  if(b == 1) return a;
  long long ans = exp(a, b/2);
  ans = (ans*ans)%mod;
  if(b%2) ans = (ans*a)%mod;
  return ans;
}

long long calc(int n, int k){
  long long ans = fact[n];
  ans = (ans*exp(fact[k], mod-2))%mod;
  ans = (ans*exp(fact[n-k], mod-2))%mod;
  return ans;
}

void solve() {
  int n, k; cin >> n >> k;
  int zero = 0, uno = 0;
  for(int i = 0; i < n; i++){
    bool t; cin >> t;
    zero += !t; uno += t;
  }

  long long ans = 0;
  for(int i = k/2+1; i <= k; i++){
    if(uno < i || zero < k-i) continue;
    ans += (calc(uno, i)*calc(zero, k-i))%mod;
    ans %= mod;
  }

  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  fact[0] = 1;
  for(int i = 1; i <= 2e5; i++) fact[i] = (fact[i-1]*i)%mod;

  int t = 1;
  cin >> t;
  while(t--) solve();
}