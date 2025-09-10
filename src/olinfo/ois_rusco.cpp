#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> value;
vector<vector<pair<long long, int>>> dp;
queue<array<int, 2>> q;
vector<vector<bool>> pres;

void sin(int x, int y){
  if(x != 0 && dp[x-1][y].first > dp[x][y].first+value[x][y]){
    dp[x-1][y].first = dp[x][y].first+value[x][y];

    if(!pres[x-1][y]){
      pres[x-1][y] = 1;
      q.push({x-1, y});
    }
  }
}

void des(int x, int y){
  if(x == n-1) return;

  if(dp[x+1][y].second == 0){
    if(dp[x+1][y].first > dp[x][y].first-value[x+1][y]){
      dp[x+1][y].first = dp[x][y].first-value[x+1][y];

      if(!pres[x+1][y]){
        pres[x+1][y] = 1;
        q.push({x+1, y});
      }
    }
  }else if(dp[x+1][y].second == -2){
    if(dp[x+1][y-1].first > dp[x][y].first){
      dp[x+1][y-1].first = dp[x][y].first;

      if(!pres[x+1][y-1]){
        pres[x+1][y-1] = 1;
        q.push({x+1, y-1});
      }
    }
  }
}

void su(int x, int y){
  if(y != 0 && dp[x][y-1].first > dp[x][y].first+value[x][y]){
    dp[x][y-1].first = dp[x][y].first+value[x][y];

    if(!pres[x][y-1]){
      pres[x][y-1] = 1;
      q.push({x, y-1});
    }
  }
}

void giu(int x, int y){
  if(y == m-1) return;

  if(dp[x][y+1].second == 0){
    if(dp[x][y+1].first > dp[x][y].first-value[x][y+1]){
      dp[x][y+1].first = dp[x][y].first-value[x][y+1];

      if(!pres[x][y+1]){
        pres[x][y+1] = 1;
        q.push({x, y+1});
      }
    }
  }else if(dp[x][y+1].second == -1){
    if(dp[x-1][y+1].first > dp[x][y].first){
      dp[x-1][y+1].first = dp[x][y].first;

      if(!pres[x-1][y+1]){
        pres[x-1][y+1] = 1;
        q.push({x-1, y+1});
      }
    }
  }
}

int main() {
  cin >> n >> m;
  
  value.resize(n, vector<int>(m));
  for(auto &i : value) for(auto &j : i) cin >> j;

  dp.resize(n, vector<pair<long long, int>>(m, {1e18, 0}));
  dp[0][0].first = 0;

  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      if(i == 0 && j == 0) continue;

      if(i != 0 && dp[i][j].first > dp[i-1][j].first-value[i][j]){
        dp[i][j].first = dp[i-1][j].first-value[i][j];
        dp[i][j].second = 1;
      }

      if(j != 0 && dp[i][j].first > dp[i][j-1].first-value[i][j]){
        dp[i][j].first = dp[i][j-1].first-value[i][j];
        dp[i][j].second = 2;
      }
    }
  }

  long long ans = -dp[n-1][m-1].first;
  int x = n-1, y = m-1;
  while(1){
    if(dp[x][y].second == 1){
      dp[x][y].second = -1;
      x--;
    }else{
      dp[x][y].second = -2;
      y--;
    }

    if(x == 0 && y == 0) break;
  }

  for(auto &i : dp) for(auto &j : i){ 
    j.first = 1e18;
    if(j.second != -1 && j.second != -2) j.second = 0;
  }

  q.push({0, 0});
  dp[0][0].first = 0; dp[0][0].second = dp[n-1][m-1].second = 0;
  pres.resize(n, vector<bool>(m));
  pres[0][0] = 1;
  while(!q.empty()){
    auto node = q.front(); q.pop();
    int x = node[0], y = node[1];
    pres[x][y] = 0;

    if(dp[x][y].second == -1){
      sin(x, y);
      des(x, y);
      giu(x, y);
    }else if(dp[x][y].second == -2){
      su(x, y);
      des(x, y);
      giu(x, y);
    }else{
      des(x, y);
      giu(x, y);
    }
  }

  cout << ans - dp[n-1][m-1].first;
}