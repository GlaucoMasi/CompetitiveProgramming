#include <bits/stdc++.h>
using namespace std;

int main() {
  int maxh = 1e9;
  int m, n; cin >> n >> m;
  vector<vector<int>> v(n, vector<int>(m));
  for(auto &i : v) for(auto &j : i) cin >> j;

  vector<vector<int>> dist(n, vector<int>(m, -1));
  dist[0][0] = 0;
  int x = 0, y = 0, xprev = -1, yprev = -1;
  while(1){
    array<int, 4> next = {maxh, maxh, maxh, maxh};

    for(int i = -1; i <= 1; i++){
      for(int j = -1; j <= 1; j++){
        if(abs(i) == abs(j)) continue;
        if(x+i == xprev && y+j == yprev) continue;
        if(x+i < 0 || x+i >= n || y+j < 0 || y+j >= m) continue;

        next = min(next, {abs(v[x][y]-v[x+i][y+j]), v[x+i][y+j], x+i, y+j});
      }
    }

    xprev = x, yprev = y;
    x = next[2], y = next[3];

    if(dist[x][y] != -1){
      cout << dist[xprev][yprev] + dist[x][y] + 1;
      break;
    }else dist[x][y] = dist[xprev][yprev]+1;
  }
}