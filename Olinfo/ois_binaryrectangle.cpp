#include <bits/stdc++.h>
using namespace std;

bool solve() {
  int n, m; cin >> n >> m;
  vector<vector<bool>> v(n, vector<bool>(m));

  int tot = 0;
  pair<int, int> up = {1e9, 1e9}, low = {-1, -1};
  for(int i = 0; i < n; i++){
    string s; cin >> s;
    for(int j = 0; j < m; j++){
      v[i][j] = (s[j] == '1');
      tot += v[i][j];
      if(v[i][j]){
        up = min(up, {i, j});
        low = max(low, {i, j});
      }
    }
  }

  if(!tot) return 0;
  
  int temp = 0;
  for(int i = up.first; i <= low.first; i++) for(int j = up.second; j <= low.second; j++) temp += v[i][j];
  return (temp == tot && temp == (low.first-up.first+1)*(low.second-up.second+1));
}

int main() {
  int t; cin >> t;
  while(t--) cout << (solve() ? '1' : '0') << '\n';
}