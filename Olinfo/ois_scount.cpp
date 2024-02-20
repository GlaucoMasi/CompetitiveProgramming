#include <bits/stdc++.h>
using namespace std;

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
  int n; cin >> n;
  unordered_map<int, int> m;

  vector<int> f;
  for(int i = 0; i < n; i++){
    int a; cin >> a;

    if(m.count(a)) f[m[a]]++;
    else{
      m[a] = f.size();
      f.push_back(1);
    }
  }

  vector<long long> fact(n+1); fact[0] = 1;
  for(long long i = 1; i <= n; i++) fact[i] = (fact[i-1]*i)%mod;

  auto calc = [&](int a, int b){ return (long long)((((fact[a]*exp(fact[b], mod-2))%mod)*exp(fact[a-b], mod-2))%mod); };

  int idx = 0;
  long long ans = 0;
  sort(f.begin(), f.end());
  for(int i = 1; i <= n; i++){
    while(idx < f.size() && f[idx] < i) idx++;

    long long temp = 1;
    for(int j = idx; j < f.size(); j++) temp = (temp*(calc(f[j], i)+1))%mod;
    temp = (temp-1+mod)%mod;
    ans = (ans+temp)%mod;
  }

  cout << ans+1;
}