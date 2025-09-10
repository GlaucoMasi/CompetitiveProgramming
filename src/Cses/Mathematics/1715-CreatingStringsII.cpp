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

  string s; cin >> s;
  vector<int> freq(26);
  for(auto i : s) freq[i-'a']++;

  long long ans = fact[s.size()];
  for(auto i : freq) ans = (ans*exp(fact[i], mod-2))%mod;
  cout << ans;
}