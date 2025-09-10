#include <bits/stdc++.h>
using namespace std;

int main() {
  int mod = 1e9 + 7;
  int n, m; cin >> n >> m;
  vector<int> v(n);
  for(auto &i : v) cin >> i;
  vector<vector<int>> memo(n, vector<int>(m+1, 0));

  long long sum = 0;
  for(int i = 1; i <= m; i++){
    if(v[0] == i || v[0] == 0) memo[0][i] = 1;
    if(n-1 == 0) sum = (sum + memo[0][i]) % mod;
  }

  for(int i = 1; i < n; i++){
    for(int j = 1; j <= m; j++){
      if(v[i] != 0 && j != v[i]) continue;
      long long ans = 0;

      if(j+1 <= m) ans += memo[i-1][j+1];
      if(j-1 >= 1) ans += memo[i-1][j-1];
      ans += memo[i-1][j];

      memo[i][j] = ans % mod;
      if(n-1 == i) sum = (sum + memo[i][j]) % mod;
    }
  }

  cout << sum;
}