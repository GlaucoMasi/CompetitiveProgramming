#include <bits/stdc++.h>
using namespace std;

int main() {
  int mod = 1e9+7, off = 5001;
  int n, x; cin >> n >> x;
  vector<int> v(n); for(auto &i : v) cin >> i;
  sort(v.begin(), v.end());

  vector<vector<long long>> dp1(n+1, vector<long long>(x+off+1)), dp2(n+1, vector<long long>(x+off+1));
  dp1[0][off] = 1;
  for(int i = 0; i < n; i++){
    for(int j = 0; j <= i; j++){
      for(int k = 0; k <= off+x; k++){
        dp2[j][k] += dp1[j][k];

        if(j && k+v[i] <= x+off) dp2[j-1][k+v[i]] += j*dp1[j][k];

        if(k-v[i] >= 0) dp2[j+1][k-v[i]] += dp1[j][k];

        dp2[j][k] += j*dp1[j][k];
      }
    }

    dp1 = dp2;
    for(auto &i : dp1) for(auto &j : i) j %= mod;
    for(auto &i : dp2) for(auto &j : i) j = 0;
  }

  long long ans = 0;
  for(int i = x; i <= x+off; i++) ans += dp1[0][i];
  cout << ans%mod;
}