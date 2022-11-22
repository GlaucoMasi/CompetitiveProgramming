#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<bool>> v;

int best = 0, curr = 0;

bool check(int x, int y){
  if(x > 1 && (v[x-1][y] + v[x-2][y] == 2)) return 0;
  if(y > 1 && (v[x][y-1] + v[x][y-2] == 2)) return 0;
  if(x > 1 && y > 1 && (v[x-1][y-1] + v[x-2][y-2]) == 2) return 0;
  if(x > 1 && y < m-2 && (v[x-1][y+1] + v[x-2][y+2]) == 2) return 0;

  return 1;
}

void f(int x, int y){
  if(y == m){
    y = 0; x++;
  }

  if(x == n){
    best = max(best, curr);
    return;
  }

  if(curr + m-y + m*(n-x-1) <= best) return;

  bool before = v[x][y];
  v[x][y] = 1;

  if(check(x, y)){
    if(!before) curr++;
    f(x, y+1);
    if(!before) curr--;
  }

  v[x][y] = before;
  
  if(!v[x][y]) f(x, y+1);
}

int main() {
  cin >> n >> m;
  v.resize(n, vector<bool>(m));

  int a;
  for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++){
      cin >> a;
      v[i][j] = a;
    }

  f(0, 0);
  cout << best;
}