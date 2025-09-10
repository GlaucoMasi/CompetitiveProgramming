#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, p; cin >> n >> p;

  vector<vector<vector<bool>>> occ(n, vector<vector<bool>>(n, vector<bool>(60)));

  while(p--){
    int a, b, c;
    cin >> a >> b >> c;
    a--; b--;

    for(int i = 0; i < c; i++){
      for(int t = i; t < c; t++){
        for(int k = t; k < 60; k += c){
          for(int j = max(a-i, 0); j <= min(a+i, n-1); j++){
            if(b + (i - abs(a-j)) < n) occ[j][b + (i - abs(a-j))][k] = 1;
            if(b - (i - abs(a-j)) >= 0) occ[j][b - (i - abs(a-j))][k] = 1;
          }
        }
      }
    }
  }

  queue<pair<pair<int, int>, int>> q;
  q.push({{0, 0}, 0});
  while(!q.empty()){
    auto [x, y] = q.front().first;
    int t = q.front().second;
    q.pop();

    if(x < 0 || y < 0 || x >= n || y >= n) continue;
    
    if(occ[x][y][t%60]) continue;
    occ[x][y][t%60] = 1;

    if(x == n-1 && y == n-1){
      cout << t;
      break;
    }

    q.push({{x, y}, t+1});
    q.push({{x+1, y}, t+1});
    q.push({{x-1, y}, t+1});
    q.push({{x, y+1}, t+1});
    q.push({{x, y-1}, t+1});
  }
}