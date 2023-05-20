#include <bits/stdc++.h>
using namespace std;

int n;
string s;

constexpr int sz = 3;

int mod = 1e9+7;
array<long long, sz> b = {29, 31, 37};
array<vector<long long>, sz> p;

bool test(int lenght){
  array<long long, sz> hash = {0};
  array<unordered_set<long long>, sz> cont;
  array<bool, sz> found = {0};
  
  for(int i = 0; i < lenght; i++){
    for(int k = 0; k < sz; k++){ hash[k] += (p[k][lenght-i-1]*(s[i]-'a'))%mod; hash[k] %= mod; }
  }

  for(int k = 0; k < sz; k++){ 
    if(cont[k].count(hash[k])) found[k] = 1;
    else cont[k].insert(hash[k]);
  }

  bool ans = 0;

  bool temp = 1;
  for(int k = 0; k < sz; k++) if(!found[k]) temp = 0;
  if(temp) ans = 1;

  for(int i = lenght; i < n; i++){
    found = {0};

    for(int k = 0; k < sz; k++){
      hash[k] = (hash[k]+mod-(p[k][lenght-1]*(s[i-lenght]-'a'))%mod)%mod;
      hash[k] = (hash[k]*b[k])%mod;
      hash[k] += (s[i]-'a'); hash[k] %= mod;

      if(cont[k].count(hash[k])) found[k] = 1;
      else cont[k].insert(hash[k]);
    }

    temp = 1;
    for(int k = 0; k < sz; k++) if(!found[k]) temp = 0;
    if(temp) ans = 1;
  }

  return ans;
}

int main() {
  cin >> n >> s;
  for(int i = 0; i < sz; i++){
    p[i].resize(n+1); p[i][0] = 1;
    for(int j = 1; j <= n; j++) p[i][j] = (p[i][j-1]*b[i])%mod;
  }

  int l = 0, r = n+1;
  while(l < r-1){
    int m = (l+r)/2;
    
    if(test(m)) l = m;
    else r = m;
  }

  cout << l;
}