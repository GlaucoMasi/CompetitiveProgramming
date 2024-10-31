#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int mod = 1e9+7;
long long exp(long long a, long long b){
  if(b == 0) return 1;
  if(b == 1) return a;

  long long ans = exp(a, b/2);
  ans = (ans*ans)%mod;
  if(b%2) ans = (ans*a)%mod;
  return ans;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  vector<long long> fact(1e6+1); fact[0] = 1;
  for(long long i = 1; i <= 1e6; i++) fact[i] = (fact[i-1]*i)%mod;

  int q; cin >> q;
  while(q--){
    int a, b; cin >> a >> b;
    cout << (((fact[a]*exp(fact[b], mod-2))%mod)*exp(fact[a-b], mod-2))%mod << '\n';
  }
}