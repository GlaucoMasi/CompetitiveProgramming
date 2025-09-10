#include <bits/stdc++.h>
using namespace std;

long long percorri(int n, long long k, long long d[], long long p[]){
  auto test = [&](long long m){
    long long curr = d[0];

    for(int i = 0; i < n; i++){
      if(curr > m) return false;
      if(curr+p[i] <= m && p[i] < curr) curr = p[i];
      curr += (i == n-1 ? k : d[i+1])-d[i];
    }

    return (curr <= m);
  };
  
  long long l = -1, r = k+1;
  while(l < r-1){
    long long m = (l+r)/2;
    if(test(m)) r = m;
    else l = m;
  }
  
  return l+1;
}