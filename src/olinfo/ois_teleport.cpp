#include <bits/stdc++.h>
using namespace std;

int main() {
  int r, c;
  cin >> r >> c;

  vector<vector<int>> grid(r, vector<int>(c)), vis(r, vector<int>(c));
  queue<pair<int, pair<int, int>>> q;

  char a;
  pair<int, int> s;
  for(int i = 0; i < r; i++){
    for(int j = 0; j < c; j++){
      cin >> a;

      if(a == '#') grid[i][j] = 1;
      else if(a == '@'){
        grid[i][j] = 2;
        vis[i][j] = 1;
        q.push({0, {i, j}});
      }else if(a == 'C'){
        grid[i][j] = 3;
        s = {i, j};
      }else if(a == 'M') grid[i][j] = 4;
    }
  }

  bool start = 0, end = 0;
  int ans = 1;
  while(!q.empty()){
    int dist = q.front().first, x = q.front().second.first, y = q.front().second.second; q.pop();

    if(grid[x][y] == 3 && !start){
      start = 1;
      ans += dist;
    }else if(grid[x][y] == 4 && !end){
      end = 1;
      ans += dist;
    }

    if(x+1 < r && !vis[x+1][y] && grid[x+1][y] != 1){
      vis[x+1][y] = 1;
      q.push({dist+1, {x+1, y}});
    }

    if(x-1 >= 0 && !vis[x-1][y] && grid[x-1][y] != 1){
      vis[x-1][y] = 1;
      q.push({dist+1, {x-1, y}});
    }

    if(y+1 < c && !vis[x][y+1] && grid[x][y+1] != 1){
      vis[x][y+1] = 1;
      q.push({dist+1, {x, y+1}});
    }

    if(y-1 >= 0 && !vis[x][y-1] && grid[x][y-1] != 1){
      vis[x][y-1] = 1;
      q.push({dist+1, {x, y-1}});
    }
  }

  vis = vector<vector<int>>(r, vector<int>(c));
  q.push({0, s});
  while(!q.empty()){
    int dist = q.front().first, x = q.front().second.first, y = q.front().second.second; q.pop();

    if(grid[x][y] == 4){
      cout << ((start && end) ? min(dist, ans) : dist);
      break;
    }

    if(x+1 < r && !vis[x+1][y] && grid[x+1][y] != 1){
      vis[x+1][y] = 1;
      q.push({dist+1, {x+1, y}});
    }

    if(x-1 >= 0 && !vis[x-1][y] && grid[x-1][y] != 1){
      vis[x-1][y] = 1;
      q.push({dist+1, {x-1, y}});
    }

    if(y+1 < c && !vis[x][y+1] && grid[x][y+1] != 1){
      vis[x][y+1] = 1;
      q.push({dist+1, {x, y+1}});
    }

    if(y-1 >= 0 && !vis[x][y-1] && grid[x][y-1] != 1){
      vis[x][y-1] = 1;
      q.push({dist+1, {x, y-1}});
    }
  }
}