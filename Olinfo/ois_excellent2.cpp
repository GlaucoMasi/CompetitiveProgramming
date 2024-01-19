#include <bits/stdc++.h>
using namespace std;

int mod = 1e9+7;
vector<map<long long, long long>> memo(3);

long long f(long long n, int m){
  if(n == 0) return (m == 0);
  if(n == 1) return (m != 0);

  if(memo[m].count(n)) return memo[m][n];

  long long ans = 0;
  if(n%2){
    for(int j = 0; j < 3; j++){
      ans = (ans + (f(n/2, j)*f(n/2, (m-j+5)%3))%mod)%mod;
      ans = (ans + (f(n/2, j)*f(n/2, (m-j+4)%3))%mod)%mod;
    }
  }else for(int j = 0; j < 3; j++) ans = (ans + (f(n/2, j)*f(n/2, (m-j+3)%3))%mod)%mod;
  return memo[m][n] = ans;
}

void solve(){
  long long n; cin >> n;
  cout << f(n, 0) << '\n';
}

int main() {
  int t; cin >> t;
  while(t--) solve();
}