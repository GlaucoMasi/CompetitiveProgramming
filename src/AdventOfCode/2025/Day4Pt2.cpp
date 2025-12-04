#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  vector<vector<bool>> grid;
  while(cin >> s) {
    grid.push_back({});
    for(auto c : s) grid.back().push_back(c == '@');
  }

  queue<pair<int, int>> q;
  vector<vector<int>> close(grid.size(), vector<int>(grid[0].size()));
  for(int i = 0; i < grid.size(); i++) {
    for(int j = 0; j < grid[0].size(); j++) {
      if(!grid[i][j]) continue;

      for(int k1 = -1; k1 <= 1; k1++) {
        for(int k2 = -1; k2 <= 1; k2++) {
          if(k1 == 0 && k2 == 0) continue;
          if(i+k1 < 0 || i+k1 > grid.size()-1) continue;
          if(j+k2 < 0 || j+k2 > grid[0].size()-1) continue;
          close[i][j] += grid[i+k1][j+k2];
        }
      }

      if(close[i][j] < 4) q.push({i, j});
    }
  }
  
  int ans = 0;
  while(!q.empty()) {
    auto [i, j] = q.front(); q.pop();

    if(!grid[i][j]) continue;
    grid[i][j] = 0;
    ans++;

    for(int k1 = -1; k1 <= 1; k1++) {
      for(int k2 = -1; k2 <= 1; k2++) {
        if(k1 == 0 && k2 == 0) continue;
        if(i+k1 < 0 || i+k1 > grid.size()-1) continue;
        if(j+k2 < 0 || j+k2 > grid[0].size()-1) continue;
        if(grid[i+k1][j+k2] && --close[i+k1][j+k2] < 4) q.push({i+k1, j+k2});
      }
    }
  }

  cout << ans;
}