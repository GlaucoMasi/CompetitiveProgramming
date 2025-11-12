#include <bits/stdc++.h>
using namespace std;

int mod = 1e9+7;
long long binexp(int b, int e) {
  if(e == 0) return 1;
  if(e == 1) return b;

  long long ans = binexp(b, e/2);
  ans = (ans*ans)%mod;
  if(e%2) ans = (ans*b)%mod;

  return ans;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  vector<int> primes;
  vector<bool> prime(1e6, 1);
  for(long long i = 2; i < 1e6; i++) {
    if(prime[i]) {
      primes.push_back(i);
      for(long long j = i*i; j < 1e6; j += i) prime[j] = 0;
    }
  }
  
  int tot = 0;
  long long n; cin >> n;
  vector<int> facts;
  for(auto p : primes) {
    if(n == 1) break;
    if(n % p == 0) facts.push_back(0);
    while(n % p == 0) {
      n /= p;
      facts.back()++;
      tot++;
    }
  }

  if(n != 1) facts.push_back(1), tot++;

  long long fact = 1;
  vector<int> inv(100); inv[0] = 1;
  for(int i = 1; i < 100; i++) {
    fact = (fact * i)%mod;
    inv[i] = binexp(fact, mod-2);
  }

  auto bin = [&](int n, int k) {
    long long res = 1;
    for(int i = n-k+1; i <= n; i++) res = (res * i)%mod;
    return (res * inv[k])%mod;
  };

  long long precalc[tot+1];
  for(int i = 0; i <= tot; i++) {
    long long ways = 1;
    for(auto f : facts) ways = (ways * bin(f+i-1, f))%mod;
    precalc[i] = ways;
  }

  long long ans = 0;
  for(int i = 1; i <= tot; i++) {
    long long curr = 0;

    for(int ones = 0; ones < i; ones++) {
      long long ways = ways = (precalc[i-ones] * bin(i, ones))%mod;
      curr = (curr + (ones%2 ? mod-ways : ways))%mod;
    }
    
    ans = (ans+curr)%mod;
  }

  cout << ans;
}