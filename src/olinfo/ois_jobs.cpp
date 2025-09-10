#include <bits/stdc++.h>
using namespace std;

int main() {
  int n; long long k; cin >> n >> k;
  vector<int> t(n), p(n);
  for(auto &i : t) cin >> i;
  for(auto &i : p) cin >> i;

  int sum = 25e4+1;
  vector<long long> dp(sum); dp[0] = 0;
  for(int i = 1; i < sum; i++) for(int j = 0; j < n; j++) if(i-t[j] >= 0 && dp[i-t[j]] != -1) dp[i] = max(dp[i], dp[i-t[j]]+p[j]);
  for(int i = 1; i < sum; i++) dp[i] = max(dp[i-1], dp[i]);

  long long best = 0;
  for(int i = 1; i < sum; i++) best = max(best, k/i*dp[i]+dp[k%i]);
  cout << best;
}