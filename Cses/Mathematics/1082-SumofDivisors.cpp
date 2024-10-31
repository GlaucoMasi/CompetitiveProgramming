#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int mod = 1e9+7;
const int inv2 = 500000004;
long long sum(long long l, long long r){ return (((((r-l+1)%mod)*((l+r)%mod))%mod)*inv2)%mod; }

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  long long n, i = 1, ans = 0; cin >> n;
  while(i <= n){
    long long last = n/(n/i);
    ans += (sum(i, last)*(n/i))%mod;
    ans %= mod;
    i = last+1;
  }

  cout << ans;
}