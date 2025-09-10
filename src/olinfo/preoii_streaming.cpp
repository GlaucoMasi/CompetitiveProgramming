#include <bits/stdc++.h>
using namespace std;

long long bfs(int n, long long k, vector<int> p, vector<int> f){
  vector<pair<int, int>> quote, costi;

  for(int i = 0; i < n; i++) quote.push_back({p[i], i}), costi.push_back({f[i], i});
  sort(quote.begin(), quote.end()); sort(costi.begin(), costi.end());

  int t = 0;
  long long tot = 0, ans = 0;
  priority_queue<pair<int, int>> pq;
  for(int i = 0; i < n; i++){
    long long quota = quote[i].first;

    while(!pq.empty() && -pq.top().first < quota){
      tot -= pq.top().second;
      pq.pop();
    }

    for(t; t < n; t++){
      int idx = costi[t].second;

      if(p[idx] < quota) continue;
      if(tot + f[idx] > k || f[idx] > quota) break;

      tot += f[idx];
      pq.push({-p[idx], f[idx]});
    }

    ans = max(ans, quota*(long long)pq.size() - tot);
  }

  return ans;
}