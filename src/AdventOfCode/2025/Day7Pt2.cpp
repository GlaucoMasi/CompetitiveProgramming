#include <bits/stdc++.h>
using namespace std;

int main() {
  string s; cin >> s;

  vector<long long> dp(s.size());
  dp[s.find('S')]++;
  
  while(cin >> s) {
    vector<long long> nxt(s.size());
    for(int i = 0; i < s.size(); i++) {
      if(s[i] == '^') {
        nxt[i-1] += dp[i];
        nxt[i+1] += dp[i];
      } else nxt[i] += dp[i];
    }
    swap(dp, nxt);
  }

  long long ans = 0;
  for(auto i : dp) ans += i;
  cout << ans;
}