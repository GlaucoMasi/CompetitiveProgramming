#include <bits/stdc++.h>
using namespace std;

int percorri(int n, long long k, int d[], int p[]){
  auto test = [&](int m){
    int curr = d[0];

    for(int i = 0; i < n; i++){
      if(curr > m) return false;
      if(curr+p[i] <= m && p[i] < curr) curr = p[i];
      curr += (i == n-1 ? k : d[i+1])-d[i];
    }

    return (curr <= m);
  };
  
  int l = -1, r = k+1;
  while(l < r-1){
    int m = (l+r)/2;
    if(test(m)) r = m;
    else l = m;
  }
  
  return l+1;
}