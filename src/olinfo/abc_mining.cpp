#include <bits/stdc++.h>
using namespace std;

int gpu(int n, int m, int v[]){
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  int l = 0, r = n;
  while(l < r-1){
    int k = (l+r)/2;

    priority_queue<int, vector<int>, greater<>> free;
    for(int i = 0; i < k; i++) free.push(0);

    bool fail = 0;
    for(int i = 0; i < n; i++){
      if(free.empty() || free.top()+v[i] > m){
        fail = 1;
        break;
      }

      auto val = free.top(); free.pop();
      if(val+v[i] < m) free.push(val+v[i]);
    }

    if(fail) l = k;
    else r = k;
  }

  return r;
}