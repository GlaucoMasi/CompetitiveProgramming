#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k; cin >> n >> k;
  vector<int> v(n);
  for(auto &i : v){
    cin >> i;
    i--;
  }

  int m; cin >> m;
  vector<set<int>> g(k+1);
  for(int i = 0; i < m; i++){
    int a, b; cin >> a >> b;
    g[a-1].insert(b-1);
  }

  vector<int> dp(n, -1e9);
  dp[n-1] = (v[n-1] != k);
  dp[n-2] = (v[n-2] != k) + dp[n-1]*g[v[n-2]].count(v[n-1]);
  
  for(int i = n-3; i >= 0; i--){
    if(v[i] == k) continue;

    if(g[v[i]].count(v[i+1])) dp[i] = max(dp[i], dp[i+1]+1);
    if(g[v[i]].count(v[i+2])) dp[i] = max(dp[i], dp[i+2]+1);
  }

  cout << max({0, dp[0], dp[1]});
}