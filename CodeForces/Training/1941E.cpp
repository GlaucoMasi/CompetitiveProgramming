#include <bits/stdc++.h>
using namespace std;

int main() {
  int t; cin >> t;
  while(t--){
    int n, m, k, d;
    cin >> n >> m >> k >> d;
 
    vector<long long> costs;
    for(int i = 0; i < n; i++){
      vector<long long> v(m), cost(m);
      for(auto &i : v) cin >> i, i++;
      deque<int> dq; dq.push_back(0);
      cost[0] = v[0];

      for(int j = 1; j < m; j++){
        while(j-dq.front()-1 > d) dq.pop_front();
        cost[j] = cost[dq.front()]+v[j];
        while(!dq.empty() && cost[dq.back()] > cost[j]) dq.pop_back();
        dq.push_back(j);
      }

      costs.push_back(cost[m-1]);
    }

    long long ans = 1e18, curr = 0;
    for(int i = 0; i < n; i++){
      curr += costs[i];
      if(i >= k) curr -= costs[i-k];
      if(i >= k-1) ans = min(ans, curr);
    }
    cout << ans << '\n';
  }
}