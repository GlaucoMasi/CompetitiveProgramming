#include <bits/stdc++.h>
using namespace std;

bool heights(int n, vector<int> z, vector<int>& h){
  for(int i = 1; i < n-2; i++) if(z[i] > z[i-1] && z[i] > z[i+1]) return 0;

  h[0] = z[0]; h[n-1] = z[n-2];
  for(int i = 1; i < n-1; i++) h[i] = min(z[i-1], z[i]);
  return 1;
}