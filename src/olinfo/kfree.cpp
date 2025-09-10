#include <bits/stdc++.h>
using namespace std;

int Trova(int n, int k, int insieme[]){
  vector<int> v(1e5+1);
  for(int i = 0; i < n; i++) v[insieme[i]]++;

  int ans = 0;
  for(int i = 1; i <= 1e5; i++){
    if(!v[i]) continue;
    if(!(i%k)) v[i] += v[i/k];
    if(i*k > 1e5 || !v[i*k]) ans += (v[i]+1)/2;
  }

  return ans;
}