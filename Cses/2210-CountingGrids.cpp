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
 
  long long n; cin >> n;
  long long tot = 0, num = 0;

  tot = (tot + exp(2, n*n))%mod;
  tot = (tot + exp(2, n*(n/2) + (n%2 ? n/2+1 : 0)))%mod;
  tot = (tot + 2LL*exp(2, (n/2)*(n/2) + (n%2 ? n/2+1 : 0)))%mod;

  cout << (tot*exp(4, mod-2))%mod;
}