#include <bits/stdc++.h>
using namespace std;

int mod = 1e9+7;
int n, k;
unordered_map<int, long long> memo;

void f(int i){
  if(i < 0) memo[i] = 0;
  else if(i <= 1) memo[i] = 1;
  else{
    if(!memo.count(i/2)) f(i/2); 
    if(!memo.count((i+2*(i%2))/2)) f((i+2*(i%2))/2);
    memo[i] = (memo[i/2]*memo[(i+2*(i%2))/2])%mod;

    for(int l = 2; l <= k; l++){
      for(int j = 1; j <= l-1; j++){
        if(!memo.count(i/2-j)) f(i/2-j);
        if(!memo.count((i+2*(i%2))/2 - l+j)) f((i+2*(i%2))/2 - l+j);
        memo[i] = (memo[i] + (memo[i/2-j] * memo[(i+2*(i%2))/2 - l+j])%mod)%mod;
      }
    }
  }
}

int progetti(int N, int K){
  n = N, k = K;
  f(n); return memo[n];
}