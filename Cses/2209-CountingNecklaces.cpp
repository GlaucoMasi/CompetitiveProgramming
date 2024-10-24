#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");
 
int mod = 1e9+7;
long long exp(long long a, int b){
  if(b == 0) return 1;
  if(b == 1) return a;
 
  long long ans = exp(a, b/2);
  ans = (ans*ans)%mod;
  if(b%2) ans = (ans*a)%mod;
 
  return ans;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
  int n, m; cin >> n >> m;
  
  vector<long long> pm(n+1); pm[0] = 1;
  for(int i = 1; i <= n; i++) pm[i] = (pm[i-1]*m)%mod;

  int t = sqrt(n);
  vector<long long> l, r;
  for(int i = 1; i <= t; i++){
    if(!(n%i)){
      l.push_back(i);
      if(i != n/i) r.push_back(n/i);
    }
  }

  long long tot = 0;
  vector<long long> ans(n+1, 0);
  auto calc = [&](long long i){
    ans[i] = (ans[i]+pm[i])%mod;
    ans[i] = (ans[i]*exp(i, mod-2))%mod;
    for(int j = 2*i; j <= n; j += i) ans[j] = (ans[j]-(ans[i]*i)%mod+mod)%mod;
    tot = (tot+ans[i])%mod;
  };
 
  for(auto i : l) calc(i);
  for(int i = r.size()-1; i >= 0; i--) calc(r[i]);

  cout << tot;
}