#include <bits/stdc++.h>
using namespace std;

int main() {
  int n; cin >> n;

  vector<int> cost(n+1, 1e9);
  for(int i = 1; i <= n; i++) for(int j = i; j <= n; j += i) cost[j] = min(cost[j], i+j/i);

  vector<int> dp(n+1, 1e9); dp[0] = 0;
  for(int i = 1; i <= n; i++){
    for(int j = 0; j < i; j++){
      int off = i-j;
      dp[i] = min(dp[i], dp[j]+cost[off]);
    }
  }

  cout << 2*dp[n];
}