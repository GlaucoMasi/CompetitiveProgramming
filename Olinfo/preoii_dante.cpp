#include <bits/stdc++.h>
using namespace std;

int rimembra(int n, int k, vector<int> v){
  int best = 0, r = -1, curr = 0;
  for(int i = 0; i < n; i++){
    while(r+1 < n && curr + !v[r+1] <= k) curr += !v[r+1], r++;
    best = max(best, r-i+1);
    curr -= !v[i];
  }

  return best;
}