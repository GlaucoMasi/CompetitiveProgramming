#include <bits/stdc++.h>
using namespace std;
ofstream fout("output.txt");

int trova(int n){
  int mod = 1e9+7;
  int fac = 1, ans = (n < 3 ? 1 : 3);
  
  for(int i = 1; i < n; i++){
    fac = ((long long)fac*i)%mod;
    ans = (ans+fac)%mod;
  }
  
  return ans;
}