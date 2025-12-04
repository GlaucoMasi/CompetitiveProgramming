#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  vector<vector<bool>> grid;
  while(cin >> s) {
    grid.push_back({});
    for(auto c : s) grid.back().push_back(c == '@');
  }

  int ans = 0;
  for(int i = 0; i < grid.size(); i++) {
    for(int j = 0; j < grid[0].size(); j++) {
      if(!grid[i][j]) continue;

      int num = 0;
      for(int k1 = -1; k1 <= 1; k1++) {
        for(int k2 = -1; k2 <= 1; k2++) {
          if(k1 == 0 && k2 == 0) continue;
          if(i+k1 < 0 || i+k1 > grid.size()-1) continue;
          if(j+k2 < 0 || j+k2 > grid[0].size()-1) continue;
          num += grid[i+k1][j+k2];
        }
      }
      
      ans += num < 4;
    }
  }

  cout << ans;
}