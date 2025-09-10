#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int mod = 1e9+7;
vector<long long> fact(1e6+1);

long long exp(int a, int b){
  if(b == 0) return 1;
  if(b == 1) return a;

  long long ans = exp(a, b/2);
  ans = (ans*ans)%mod;
  if(b%2) ans = (ans*a)%mod;

  return ans;
}

long long bin(int a, int b){
  return (((fact[a]*exp(fact[b], mod-2))%mod)*exp(fact[a-b], mod-2))%mod;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  fact[0] = 1;
  for(long long i = 1; i <= 1e6; i++) fact[i] = (fact[i-1]*i)%mod;

  int n; cin >> n;
  if(n%2) cout << 0;
  else cout << (bin(n, n/2)*exp(n/2+1, mod-2))%mod;
}