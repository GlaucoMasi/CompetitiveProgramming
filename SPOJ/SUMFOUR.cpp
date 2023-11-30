#include <bits/stdc++.h>
using namespace std;

int main() {
  int n; cin >> n;
  int v[4][n];
  for(int i = 0; i < n; i++) for(int j = 0; j < 4; j++) cin >> v[j][i];

  int m[n*n+1]; m[0] = -2e9;
  for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) m[n*i+j+1] = v[0][i]+v[1][j];
  sort(m, m+n*n+1);

  int ans = 0;
  for(int i = 0; i < n; i++) for(int j = 0; j < n; j++){
    int t = -v[2][i]-v[3][j];
    auto range = equal_range(m, m+n*n+1, t);
    ans += range.second-range.first;
  }
  cout << ans;
}