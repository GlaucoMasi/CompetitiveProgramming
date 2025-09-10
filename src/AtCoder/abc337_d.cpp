#include <bits/stdc++.h>
using namespace std;

int main() {
  int h, w, k;
  cin >> h >> w >> k;
  vector<string> grid(h);
  for(auto &i : grid) cin >> i;

  int ans = 1e9;
  vector<vector<pair<int, int>>> row(h, vector<pair<int, int>>(w)), col(h, vector<pair<int, int>>(w));
  for(int i = 0; i < h; i++){
    for(int j = 0; j < w; j++){
      if(j != 0) row[i][j] = row[i][j-1];
      if(grid[i][j] == 'o') row[i][j].first++;
      else if(grid[i][j] == '.') row[i][j].second++;

      if(i != 0) col[i][j] = col[i-1][j];
      if(grid[i][j] == 'o') col[i][j].first++;
      else if(grid[i][j] == '.') col[i][j].second++;

      if(j >= k-1){
        pair<int, int> temp = row[i][j];
        if(j-k >= 0){
          temp.first -= row[i][j-k].first;
          temp.second -= row[i][j-k].second;
        }

        if(temp.first + temp.second == k) ans = min(ans, temp.second);
      }

      if(i >= k-1){
        pair<int, int> temp = col[i][j];
        if(i-k >= 0){
          temp.first -= col[i-k][j].first;
          temp.second -= col[i-k][j].second;
        }

        if(temp.first + temp.second == k) ans = min(ans, temp.second);
      }
    }
  }

  if(ans == 1e9) cout << -1;
  else cout << ans;
}