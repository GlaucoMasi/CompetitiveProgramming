#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m; cin >> n >> m;
  vector<string> v(n);
  for(auto &i : v) cin >> i;

  int best = 0;

  for(int i = 0; i < n; i++){
    int curr = 1;
    for(int j = 1; j < m; j++){
      if(v[i][j] == v[i][j-1]) curr++;
      else curr = 1;
      best = max(best, curr);
    }
  }

  for(int i = 0; i < m; i++){
    int curr = 1;
    for(int j = 1; j < n; j++){
      if(v[j][i] == v[j-1][i]) curr++;
      else curr = 1;
      best = max(best, curr);
    }
  }

  for(int i = 0; i < max(n, m); i++){
    int x = i+1, y = 1, curr = 1;
    while(x < n && y < m){
      if(v[x][y] == v[x-1][y-1]) curr++;
      else curr = 1;
      best = max(best, curr);
      x++; y++;
    }

    x = 1, y = i+1, curr = 1;
    while(x < n && y < m){
      if(v[x][y] == v[x-1][y-1]) curr++;
      else curr = 1;
      best = max(best, curr);
      x++; y++;
    }
  }

  for(int i = 0; i < max(n, m); i++){
    int x = i+1, y = 1, curr = 1;
    while(x >= 0 && x < n-1 && y < m){
      if(v[x][y] == v[x+1][y-1]) curr++;
      else curr = 1;
      best = max(best, curr);
      x--; y++;
    }

    x = n-2, y = i+1, curr = 1;
    while(x >= 0 && y < m){
      if(v[x][y] == v[x+1][y-1]) curr++;
      else curr = 1;
      best = max(best, curr);
      x--; y++;
    }
  }

  cout << best;
}