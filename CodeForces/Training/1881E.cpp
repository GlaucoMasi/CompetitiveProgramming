#include <bits/stdc++.h>
using namespace std;

int main() {
  int t; cin >> t;
  while(t--){
    int n; cin >> n;
    vector<int> v(n);
    for(auto &i : v) cin >> i;

    vector<int> dp(n+1);
    for(int i = n-1; i >= 0; i--){
      dp[i] = dp[i+1]+1;
      if(i+v[i]+1 <= n) dp[i] = min(dp[i], dp[i+v[i]+1]);
    }
    
    cout << dp[0] << '\n';
  }
}