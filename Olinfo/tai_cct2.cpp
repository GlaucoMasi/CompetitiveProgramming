#include <bits/stdc++.h>
using namespace std;

int speedrunna(int n, int k, int a, int b){
  int t = 1, car = 1;
  
  vector<int> v(k+1, 2e9);
  v[0] = 0;

  for(int i = 0; i < n; i++){
    vector<int> next(k+1, 2e9);
    next[0] = v[k];

    for(int j = 0; j <= k; j++){
      if(v[j] == 2e9) continue;
      
      next[min(k, j+car)] = min(next[min(k, j+car)], v[j]+t);
    }

    v = next;
    t = (t*a)%1000, car = (car*b)%k;
  }

  int ans = 2e9;
  for(auto i : v) ans = min(ans, i);
  return ans;
}