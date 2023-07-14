#include <bits/stdc++.h>
using namespace std;

long long smaltisci(int n, int m, vector<int> a, vector<vector<int>> b){
  vector<int> rem(m); vector<bool> prop(n);
  vector<long long> ans(n, 1e18), tot(m);
  vector<vector<int>> v(n);
  priority_queue<pair<long long, int>> pq;

  for(int i = 0; i < m; i++){
    rem[i] = b[i].size();
    for(auto j : b[i]) v[j].push_back(i);
  
    if(b[i].size() == 0){
      ans[a[i]] = 1;
      pq.push({-1, a[i]});
    }
  }

  while(!pq.empty()){
    int i = pq.top().second; pq.pop();
    
    if(prop[i]) continue;
    prop[i] = 1;

    for(auto j : v[i]){
      rem[j]--;
      tot[j] += ans[i];

      if(!rem[j] && ans[a[j]] > tot[j]+1){
        ans[a[j]] = tot[j]+1;
        pq.push({-ans[a[j]], a[j]});
      }
    }
  }

  return ans[0];
}