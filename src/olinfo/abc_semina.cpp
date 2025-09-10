#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
  int n; cin >> n;
  vector<vector<int>> v(200, vector<int>(200, 0));
  
  int ans = 0;
  for(int i = 0; i < n; i++){
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    a += 100, b += 100, c += 100, d += 100;

    for(int x = a; x < c; x++) for(int y = d; y < b; y++) v[x][y]++;
  }

  for(auto i : v) for(auto j : i) ans = max(ans, j);
  cout << ans;
}