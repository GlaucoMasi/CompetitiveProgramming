#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> age;
vector<vector<long long>> l, r, up, down;

int main() {
  cin >> n >> m;
  age.resize(n, vector<int>(m));
  l = r = up = down = vector<vector<long long>>(n, vector<long long>(m));

  long long tot = 0;
  for(auto &i : age) for(auto &j : i){
    cin >> j;
    tot += j;
  }

  for(int y = 0; y < m; y++){
    for(int x = 0; x < n; x++){
      l[x][y] = age[x][y] + (y != 0 ? age[x][y-1] : 0);

      if(x != 0 && y != 0) l[x][y] += l[x-1][y-1];
      if(x != n-1 && y != 0) l[x][y] += l[x+1][y-1];

      if(y > 1 && ((x != 0 && y != 0) && (x != n-1 && y != 0))) l[x][y] -= l[x][y-2];
      else if(y > 1 && (!(x != 0 && y != 0) && !(x != n-1 && y != 0))) l[x][y] += l[x][y-2];
    }
  }

  for(int y = m-1; y >= 0; y--){
    for(int x = n-1; x >= 0; x--){
      r[x][y] = age[x][y] + (y != m-1 ? age[x][y+1] : 0);

      if(x != n-1 && y != m-1) r[x][y] += r[x+1][y+1];
      if(x != 0 && y != m-1) r[x][y] += r[x-1][y+1];

      if(y < m-2 && ((x != n-1 && y != m-1) && (x != 0 && y != m-1))) r[x][y] -= r[x][y+2];
      else if(y < m-2 && (!(x != n-1 && y != m-1) && !(x != 0 && y != m-1))) r[x][y] += r[x][y+2];
    }
  }

  for(int x = 0; x < n; x++){
    for(int y = 0; y < m; y++){
      up[x][y] = age[x][y] + (x != 0 ? age[x-1][y] : 0);

      if(x != 0 && y != 0) up[x][y] += up[x-1][y-1];
      if(x != 0 && y != m-1) up[x][y] += up[x-1][y+1];

      if(x > 1 && ((x != 0 && y != 0) && (x != 0 && y != m-1))) up[x][y] -= up[x-2][y];
      else if(x > 1 && (!(x != 0 && y != 0) && !(x != 0 && y != m-1))) up[x][y] += up[x-2][y];
    }
  }

  for(int x = n-1; x >= 0; x--){
    for(int y = m-1; y >= 0; y--){
      down[x][y] = age[x][y] + (x != n-1 ? age[x+1][y] : 0);

      if(x != n-1 && y != m-1) down[x][y] += down[x+1][y+1];
      if(x != n-1 && y != 0) down[x][y] += down[x+1][y-1];

      if(x < n-2 && ((x != n-1 && y != m-1) && (x != n-1 && y != 0))) down[x][y] -= down[x+2][y];
      else if(x < n-2 && (!(x != n-1 && y != m-1) && !(x != n-1 && y != 0))) down[x][y] += down[x+2][y];
    }
  }

  pair<long long, pair<int, int>> ans; ans.first = -1e9;
  for(int x = 0; x < n; x++){
    for(int y = 0; y < m; y++){
      int dist = min(min(x, y), min(n-1-x, m-1-y));

      long long sum = l[x][y+dist] + r[x][y-dist] + (x-dist-1 >= 0 ? up[x-dist-1][y] : 0) + (x+dist+1 < n ? down[x+dist+1][y] : 0) - tot;
      ans = max(ans, {sum, {x, y}});
    }    
  }

  cout << ans.second.first << " " << ans.second.second;
}