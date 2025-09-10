#include <bits/stdc++.h>
using namespace std;

int sz = 500001;
constexpr int k = 512;

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);  
  int q; cin >> q;
  vector<int> v(sz);
  vector<vector<int>> prec(k, vector<int>(k));

  while(q--){
    int t, x, y; cin >> t >> x >> y;

    if(t == 1){
      v[x] += y;
      for(int i = 1; i < k; i++) prec[i][x%i] += y;
    }else{
      if(x < k) cout << prec[x][y] << '\n';
      else{
        int ans = 0;
        for(int i = y; i < sz; i += x) ans += v[i];
        cout << ans << '\n';
      }
    }
  }
}