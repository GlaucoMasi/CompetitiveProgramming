#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int mod = 1e9+7;
unordered_map<long long, long long> memo;
long long f(long long n){
  if(n <= 1) return n;
  if(memo.count(n)) return memo[n];

  long long ans;
  if(n%2) ans = ((f((n+1)/2)*f((n+1)/2))%mod + (f((n+1)/2-1)*f((n+1)/2-1))%mod)%mod;
  else ans = ((((2LL*f(n/2-1))%mod + f(n/2))%mod)*f(n/2))%mod;

  return memo[n] = ans;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  long long n; cin >> n;
  cout << f(n);  
}