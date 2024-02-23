#include <bits/stdc++.h>
using namespace std;

int gioca(int n, int k, vector<vector<int>> m){
  int ans = 0, high = -1;
  priority_queue<array<int, 3>> pq;
  for(int i = 0; i < n; i++) pq.push({-m[i][0], i, 0});

  for(int i = 0; i < n*k; i++){
    auto [a, b, c] = pq.top(); pq.pop();

    if(high < -a) ans++;
    high = max(high, -a);
  
    if(c+1 < k) pq.push({-m[b][c+1], b, c+1});
  }

  return ans;
}