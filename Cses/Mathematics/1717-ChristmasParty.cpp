#include <bits/stdc++.h>
using namespace std;

int mod = 1e9+7;
vector<long long> memo;

long long f(long long n){
  if(memo[n] != -1) return memo[n];
  return memo[n] = ((n-1)*(f(n-1) + f(n-2)))%mod;
}

int main() {
  int n; cin >> n;
  memo.resize(n+1, -1); memo[1] = 0; memo[2] = 1;
  cout << f(n);
}