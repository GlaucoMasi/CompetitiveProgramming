#include <bits/stdc++.h>
using namespace std;

int main() {
  int n; cin >> n;
  vector<vector<char>> v(n, vector<char>(n));

  for(auto &i : v) for(auto &j : i) cin >> j;

  vector<vector<vector<int>>> dist(n, vector<vector<int>>(n, vector<int>(4, 1e9)));
  dist[0][0] = {0, 0, 0, 0};
  deque<array<int, 3>> dq;
  dq.push_back({0, 0, 0});

  while(!dq.empty()){
    auto [x, y, dir] = dq.front(); dq.pop_front();

    if(v[x][y] == '#') continue;

    if(x == n-1 && y == n-1){
      cout << dist[x][y][dir];
      return 0;
    }
    
    if(x > 0 && dist[x-1][y][0] > dist[x][y][dir] + (dir != 0 && v[x][y] != 'T')){
      dist[x-1][y][0] = dist[x][y][dir] + (dir != 0 && v[x][y] != 'T');

      if(dir != 0 && v[x][y] != 'T') dq.push_back({x-1, y, 0});
      else dq.push_front({x-1, y, 0});
    }
    
    if(y < n-1 && dist[x][y+1][1] > dist[x][y][dir] + (dir != 1 && v[x][y] != 'T')){
      dist[x][y+1][1] = dist[x][y][dir] + (dir != 1 && v[x][y] != 'T');

      if(dir != 1 && v[x][y] != 'T') dq.push_back({x, y+1, 1});
      else dq.push_front({x, y+1, 1});
    }

    if(x < n-1 && dist[x+1][y][2] > dist[x][y][dir] + (dir != 2 && v[x][y] != 'T')){
      dist[x+1][y][2] = dist[x][y][dir] + (dir != 2 && v[x][y] != 'T');

      if(dir != 2 && v[x][y] != 'T') dq.push_back({x+1, y, 2});
      else dq.push_front({x+1, y, 2});
    }

    if(y > 0 && dist[x][y-1][3] > dist[x][y][dir] + (dir != 3 && v[x][y] != 'T')){
      dist[x][y-1][3] = dist[x][y][dir] + (dir != 3 && v[x][y] != 'T');

      if(dir != 3 && v[x][y] != 'T') dq.push_back({x, y-1, 3});
      else dq.push_front({x, y-1, 3});
    }
  }

  cout << -1;
}