#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, d;
  cin >> n >> d;
  
  vector<int> dp(d);
  vector<array<int, 3>> v(n);
  for(int k = 0; k < 3; k++) for(auto &i : v) cin >> i[k], i[k] -= (k != 2);

  for(auto [l, r, x] : v) for(int j = d-x-1; j >= 0; j--) dp[j+x] = max(dp[j+x], dp[j]+max(0, r-max(l, j+x)+1));
  
  cout << *max_element(dp.begin(), dp.end());
}