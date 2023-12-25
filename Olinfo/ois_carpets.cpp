#include <bits/stdc++.h>
using namespace std;

int main() {
  int r, c, k, t = 1e4;
  cin >> r >> c >> k;
  vector<array<int, 4>> v(k, {t, t, -t, -t});

  for(int i = 0; i < r; i++){
    for(int j = 0; j < c; j++){
      int a; cin >> a; 
      if(!a) continue; a--;
      v[a][0] = min(v[a][0], r-i-1);
      v[a][1] = min(v[a][1], j);
      v[a][2] = max(v[a][2], r-i-1);
      v[a][3] = max(v[a][3], j);
    }
  }

  for(auto [a, b, c, d] : v) cout << b << " " << a << " " << d+1 << " " << c+1 << '\n';
}