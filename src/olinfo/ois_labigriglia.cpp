#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

deque<array<int, 3>> q;
vector<vector<vector<int>>> dist;

void back(int x, int y, int quad, int d){
  if(dist[x][y][quad] <= d) return;
  dist[x][y][quad] = d;

  q.push_back({x, y, quad});
}

void front(int x, int y, int quad, int d){
  if(dist[x][y][quad] <= d) return;
  dist[x][y][quad] = d;

  q.push_front({x, y, quad});
}

int main() {
  int n, m; fin >> n >> m;
  
  vector<vector<int>> v(n, vector<int>(m));
  for(auto &i : v) for(auto &j : i) fin >> j;

  dist = vector<vector<vector<int>>>(n, vector<vector<int>>(m, vector<int>(4, 1e9)));
  back(0, 0, 0, 0);
  int ans = -1;

  while(!q.empty()){
    auto t = q.front(); q.pop_front();
    int x = t[0], y = t[1], quad = t[2], d = dist[x][y][quad];

    if(x == n-1 && y == m-1 && quad == 2){
      ans = d+1;
      break;
    }

    if(quad == 0){
      if(x > 0) back(x-1, y, 3, d+1);
      if(y > 0) back(x, y-1, 1, d+1);
      if(x > 0 && y > 0) back(x-1, y-1, 2, d+1);

      if(!(v[x][y] & (1<<0))) front(x, y, 1, d);
      if(!(v[x][y] & (1<<3))) front(x, y, 3, d);
    }else if(quad == 1){
      if(x > 0) back(x-1, y, 2, d+1);
      if(y < m-1) back(x, y+1, 0, d+1);
      if(x > 0 && y < m-1) back(x-1, y+1, 3, d+1);

      if(!(v[x][y] & (1<<0))) front(x, y, 0, d);
      if(!(v[x][y] & (1<<1))) front(x, y, 2, d);
    }else if(quad == 2){
      if(x < n-1) back(x+1, y, 1, d+1);
      if(y < m-1) back(x, y+1, 3, d+1);
      if(x < n-1 && y < m-1) back(x+1, y+1, 0, d+1);

      if(!(v[x][y] & (1<<1))) front(x, y, 1, d);
      if(!(v[x][y] & (1<<2))) front(x, y, 3, d);
    }else{
      if(x < n-1) back(x+1, y, 0, d+1);
      if(y > 0) back(x, y-1, 2, d+1);
      if(x < n-1 && y > 0) back(x+1, y-1, 1, d+1);

      if(!(v[x][y] & (1<<2))) front(x, y, 2, d);
      if(!(v[x][y] & (1<<3))) front(x, y, 0, d);
    }
  }

  fout << ans;
}