#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m; cin >> n >> m;
  vector<vector<int>> v(n, vector<int>(m));
  for(int i = 0; i < n; i++){
    string t; cin >> t;
    for(int j = 0; j < m; j++) v[i][j] = (t[j]-'0');
  }

  unordered_map<int, int> app;

  for(int i = 0; i < n; i++){
    int t = 0, rev = 0;
    for(int j = 0; j < m; j++){
      t += v[i][j]; rev += v[i][j]*1000;
      if(j >= 3){ app[t]++; app[rev]++; }
      if(j >= 3){ t -= v[i][j-3]*1000; rev -= v[i][j-3]; }
      t *= 10; rev /= 10;
    }
  }

  for(int j = 0; j < m; j++){
    int t = 0, rev = 0;
    for(int i = 0; i < n; i++){
      t += v[i][j]; rev += v[i][j]*1000;
      if(i >= 3){ app[t]++; app[rev]++; }
      if(i >= 3){ t -= v[i-3][j]*1000; rev -= v[i-3][j]; }
      t *= 10; rev /= 10;
    }
  }

  auto diag = [&] {
    for(int i = 0; i < max(n, m); i++){
      int x = i, y = 0;
      int t = 0, rev = 0;
      while(x < n && y < m){
        t += v[x][y]; rev += v[x][y]*1000;
        if(y >= 3){ app[t]++; app[rev]++; }
        if(y >= 3){ t -= v[x-3][y-3]*1000; rev -= v[x-3][y-3]; }
        t *= 10; rev /= 10;
        x++; y++;
      }

      t = rev = 0;
      x = 0, y = i;
      while(x < n && y > 0 && y < m){
        t += v[x][y]; rev += v[x][y]*1000;
        if(x >= 3){ app[t]++; app[rev]++; }
        if(x >= 3){ t -= v[x-3][y-3]*1000; rev -= v[x-3][y-3]; }
        t *= 10; rev /= 10;
        x++; y++;
      }
    }
  };
  
  diag();
  reverse(v.begin(), v.end());
  diag();

  pair<int, int> ans = {0, 0};
  for(auto [num, count] : app){
    if(num < 1000) continue;
    if(count > ans.second){
      ans.second = count;
      ans.first = num;
    }else if(count == ans.second) ans.first = min(ans.first, num);
  }

  cout << ans.first << " " << ans.second;
}