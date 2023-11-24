#include <bits/stdc++.h>
using namespace std;

int n, m;

bool solve() {
  int x, y, a1, b1, a2, b2;
  cin >> x >> y >> a1 >> b1 >> a2 >> b2;
  x--; y--; a1--; b1--; a2--; b2--;

  vector<vector<int>> dist(n, vector<int>(m, -1));
  queue<array<int, 3>> q;
  q.push({a1, b1, 0}); q.push({a2, b2, 0});

  while(!q.empty()){
    auto t = q.front(); q.pop();
    int x = t[0], y = t[1], d = t[2];

    if(x+1 < n && dist[x+1][y] == -1){
      dist[x+1][y] = d+1;
      q.push({x+1, y, d+1});
    }

    if(x-1 >= 0 && dist[x-1][y] == -1){
      dist[x-1][y] = d+1;
      q.push({x-1, y, d+1});
    }

    if(y+1 < m && dist[x][y+1] == -1){
      dist[x][y+1] = d+1;
      q.push({x, y+1, d+1});
    }

    if(y-1 >= 0 && dist[x][y-1] == -1){
      dist[x][y-1] = d+1;
      q.push({x, y-1, d+1});
    }
  }

  q.push({x, y, 0});
  while(!q.empty()){
    auto t = q.front(); q.pop();
    int x = t[0], y = t[1], d = t[2];

    if(x == 0 || y == 0 || x == n-1 || y == m-1) return 1;

    if(x+1 < n && dist[x+1][y] > d+1){
      dist[x+1][y] = 0;
      q.push({x+1, y, d+1});
    }

    if(x-1 >= 0 && dist[x-1][y] > d+1){
      dist[x-1][y] = 0;
      q.push({x-1, y, d+1});
    }

    if(y+1 < m && dist[x][y+1] > d+1){
      dist[x][y+1] = 0;
      q.push({x, y+1, d+1});
    }

    if(y-1 >= 0 && dist[x][y-1] > d+1){
      dist[x][y-1] = 0;
      q.push({x, y-1, d+1});
    }
  }

  return 0;
}

int main() {
  cin >> n >> m;
  int t; cin >> t;
  while(t--){
    if(solve()) cout << "YES\n";
    else cout << "NO\n";
  }
}