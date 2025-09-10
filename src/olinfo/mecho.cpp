#include <bits/stdc++.h>
using namespace std;

int main() {
  ifstream cin("input.txt");
  ofstream cout("output.txt");

  int n, s; cin >> n >> s;
  vector<vector<char>> g(n, vector<char>(n));
  for(auto &i : g) for(auto &j : i) cin >> j;

  queue<array<int, 3>> q;
  pair<int, int> start;
  for(int i = 0; i < n; i++) for(int j = 0; j < n; j++){
    if(g[i][j] == 'M') start = {i, j};
    if(g[i][j] == 'H') q.push({i, j, 0});
  }

  vector<vector<int>> free(n, vector<int>(n, 1e9));
  while(!q.empty()){
    auto [x, y, d] = q.front(); q.pop();
    
    if(x < 0 || y < 0 || x >= n || y >= n) continue;
    if(g[x][y] == 'D' || g[x][y] == 'T') continue;
    if(free[x][y] != 1e9) continue;
    free[x][y] = d; 

    q.push({x+1, y, d+1});
    q.push({x-1, y, d+1});
    q.push({x, y+1, d+1});
    q.push({x, y-1, d+1});
  }

  int l = -1, r = n*n;
  while(l < r-1){
    int m = (l+r)/2;

    bool ok = 0;
    vector<vector<bool>> vis(n, vector<bool>(n));
    queue<array<int, 4>> b; b.push({start.first, start.second, m, s});
    while(!b.empty()){
      auto [x, y, d, st] = b.front(); b.pop();

      if(x < 0 || y < 0 || x >= n || y >= n) continue;

      if(st == 0){
        st = s;
        d++;
      }

      if(vis[x][y]) continue; vis[x][y] = 1;
      if(g[x][y] == 'T') continue;
      if(free[x][y] <= d) continue;
      
      if(g[x][y] == 'D'){
        ok = 1;
        break;
      }

      b.push({x+1, y, d, st-1});
      b.push({x-1, y, d, st-1});
      b.push({x, y+1, d, st-1});
      b.push({x, y-1, d, st-1});
    }

    if(ok) l = m;
    else r = m;
  }

  cout << l;
}