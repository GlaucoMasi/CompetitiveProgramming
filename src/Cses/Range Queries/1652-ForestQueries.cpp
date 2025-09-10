#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, q; cin >> n >> q;
  vector<vector<int>> v(n+1, vector<int>(n+1));

  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= n; j++){
      char c; cin >> c;
      if(c == '*') v[i][j] = 1;
      v[i][j] += v[i][j-1];
    }
  }

  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= n; j++){
      v[i][j] += v[i-1][j];
    }
  }

  while(q--){
    int a, b, c, d; cin >> a >> b >> c >> d;
    cout << v[c][d] + v[a-1][b-1] - v[a-1][d] - v[c][b-1] << '\n';
  }
}