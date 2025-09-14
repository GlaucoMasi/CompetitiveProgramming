#include <bits/stdc++.h>
using namespace std;

int conta(int n, int k, vector<int>& v){
  int diff = 0; long long prod = 1;
  int l = 0, r = 0;    
  int mod = 46337;

  vector<int> inv(1e5); inv[0] = 0; inv[1] = 1;
  for(int i = 2; i <= 1e5; i++) inv[i] = (mod-(mod/i)*inv[mod%i]%mod)%mod;

  vector<int> pres(k); pres[v[0]] = 1; diff++;

  pair<int, long long> ans = {n+1, 0};

  while(1) {
    if(diff == k){
      if(ans.first > r-l+1) ans = {r-l+1, prod%mod};
      else if(ans.first == r-l+1) ans.second = (ans.second+prod)%mod;
    
      if(l == n-1) break;

      pres[v[l]]--;
      
      int t = pres[v[l]];
      if(!t) diff--;
      else prod = (prod*inv[t+1]*t)%mod;

      l++;

      if(l > r){
        r++;

        if(!pres[v[r]]) diff++;
        pres[v[r]]++;

        int t = pres[v[r]];
        if(t != 1) prod = (prod*inv[t-1]*t)%mod;
      }
    }else{
      if(r == n-1) break;

      r++;

      if(!pres[v[r]]) diff++;
      pres[v[r]]++;

      int t = pres[v[r]];
      if(t != 1) prod = (prod*inv[t-1]*t)%mod;
    }
  }

  return ans.second;
}