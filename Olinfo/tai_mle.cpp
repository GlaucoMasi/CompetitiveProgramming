#include <bits/stdc++.h>
using namespace std;

void Colora(int n, int q, vector<int> &a, vector<int> &b, vector<int> &col, vector<int> &murale){
  vector<int> next(n);
  iota(next.begin(), next.end(), 1);
  for(auto &i : murale) i = -1;

  for(int i = q-1; i >= 0; i--){
    int l = a[i], r = b[i], c = col[i];

    while(l <= r){
      if(murale[l] == -1) murale[l] = c;
      int t = next[l];
      next[l] = r+1;
      l = t;
    }
  }

  for(auto &i : murale)
    if(i == -1) i = 0;
}