#include <bits/stdc++.h>
using namespace std;

int main() {
  int mod = 1e9 + 7;
  int n; cin >> n;
  vector<vector<int>> v(n, vector<int>(n, 1));

  char c;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      cin >> c;
      if(c == '*') v[i][j] = 0;
    }
  }

  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      int over = i > 0 ? v[i-1][j] : 0;
      int left = j > 0 ? v[i][j-1] : 0;
      if(i == 0 && j == 0) over = 1;
      if(v[i][j]) v[i][j] = (over + left) % mod;
    }
  }

  cout << v[n-1][n-1];
}