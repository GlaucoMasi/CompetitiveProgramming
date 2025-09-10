#include <bits/stdc++.h>
using namespace std;

int n, m; 

bool check(int x, int y){ return (x >= 0 && y >= 0 && x < n && y < m); }

int main() {
  cin >> n >> m;
  vector<vector<bool>> v(n, vector<bool>(m));

  queue<pair<pair<int, int>, bool>> q;
  pair<int, int> start;

  char c;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      cin >> c;

      if(c == 'A') start = {i, j};
      else if(c == '#') v[i][j] = 1;
      else if(c == 'M') q.push({{i, j}, 1});
    }
  }

  vector<vector<char>> dir(n, vector<char>(m));
  q.push({start, 0});
  
  while(!q.empty()){
    auto curr = q.front(); q.pop();
    int x = curr.first.first, y = curr.first.second;
    bool monster = curr.second;
    
    if(v[x][y]) continue;
    v[x][y] = 1;

    if(monster){
      for(int i = -1; i < 2; i++){
        for(int j = -1; j < 2; j++){
          if(abs(i) != abs(j) && check(x+i, y+j) && !v[x+i][y+j]) q.push({{x+i, y+j}, 1});
        }
      }

      continue;
    }

    if(x == 0 || y == 0 || x == n-1 || y == m-1){
      string path = "";

      while(make_pair(x, y) != start){
        path += dir[x][y];
        
        if(dir[x][y] == 'D') x--;
        else if(dir[x][y] == 'U') x++;
        else if(dir[x][y] == 'R') y--;
        else if(dir[x][y] == 'L') y++;
      }

      cout << "YES" << endl << path.size() << endl;
      for(int i = path.size()-1; i >= 0; i--) cout << path[i];
      exit(0);
    }

    if(check(x+1, y) && !v[x+1][y]){
      dir[x+1][y] = 'D';
      q.push({{x+1, y}, 0});
    }

    if(check(x-1, y) && !v[x-1][y]){
      dir[x-1][y] = 'U';
      q.push({{x-1, y}, 0});
    }

    if(check(x, y+1) && !v[x][y+1]){
      dir[x][y+1] = 'R';
      q.push({{x, y+1}, 0});
    }

    if(check(x, y-1) && !v[x][y-1]){
      dir[x][y-1] = 'L';
      q.push({{x, y-1}, 0});
    }
  }

  cout << "NO";
}