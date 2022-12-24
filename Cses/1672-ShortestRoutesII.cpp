#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m, q; cin >> n >> m >> q;
  vector<vector<long long>> d(n, vector<long long>(n, 1e18));
  for(int i = 0; i < n; i++) d[i][i] = 0;

  int a, b, c;
  while(m--){
    cin >> a >> b >> c;
    d[a-1][b-1] = min(d[a-1][b-1], (long long)c);
    d[b-1][a-1] = min(d[b-1][a-1], (long long)c);
  }

  for(int k = 0; k < n; k++){
    for(int i = 0; i < n; i++){
      for(int j = 0; j < n; j++){
        if(d[i][k]+d[k][j] < d[i][j] && (i == k || k == j)) cout << i << " " << j << endl;
        d[i][j] = min(d[i][j], d[i][k]+d[k][j]);
      }
    }
  }

  while(q--){
    cin >> a >> b;
    cout << (d[a-1][b-1] == 1e18 ? -1 : d[a-1][b-1]) << endl;
  }
}