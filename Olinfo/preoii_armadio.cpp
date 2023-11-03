#include <bits/stdc++.h>
using namespace std;

void evadi(int q, vector<int>& n){
  int maxn = 4e6+5;
  vector<int> phi(maxn);
  for(int i = 2; i < maxn; i++) phi[i] = i;
  for(int i = 2; i < maxn; i++) if(phi[i] == i) for(int j = i; j < maxn; j += i) phi[j] -= phi[j]/i;

  for(auto &k : n){
    int tot = 0, rad = sqrt(k);
    for(int i = 1; i < sqrt(k); i++) if(!(k%i)) tot += phi[k/i-1] + phi[i-1];
    if(rad * rad == k) tot += phi[rad-1];
    k = tot;
  }
}