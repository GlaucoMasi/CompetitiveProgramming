#include <bits/stdc++.h>
using namespace std;

char solve() {
  vector<vector<char>> v(3, vector<char>(3));
  for(auto &i : v) for(auto &j : i) cin >> j;

  for(int i = 0; i < 3; i++){
    char riga = v[i][0], colonna = v[0][i];

    for(int j = 1; j < 4 && riga != '.'; j++){
      if(j == 3) return riga;
      if(v[i][j] != riga) break;
    }

    for(int j = 1; j < 4 && colonna != '.'; j++){
      if(j == 3) return colonna;
      if(v[j][i] != colonna) break;
    }
  }

  if(v[1][1] != '.' && v[0][0] == v[1][1] && v[1][1] == v[2][2]) return v[1][1];
  if(v[1][1] != '.' && v[0][2] == v[1][1] && v[1][1] == v[2][0]) return v[1][1];
  return '.';
}

int main() {
  int t; cin >> t;
  while(t--){
    char ans = solve();
    if(ans == '.') cout << "DRAW";
    else cout << ans;
    cout << '\n';
  }
}