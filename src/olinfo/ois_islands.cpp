#include <bits/stdc++.h>
using namespace std;

int n, m;
bool island;
vector<vector<int>> v;
vector<vector<bool>> vis;

void f(int i, int j){
  if(i < 0 || i > n-1 || j < 0 || j > m-1) return;

  if(!v[i][j]) return;
  if(v[i][j] == 2) island = 0;

  if(vis[i][j]) return;
  vis[i][j] = 1;

  f(i+1, j);
  f(i-1, j);
  f(i, j+1);
  f(i, j-1);
  return;
}

int main() {
  cin >> n >> m;
  v.resize(n, vector<int>(m, 1));
  vis.resize(n, vector<bool>(m, 0));

  for(int i = 0; i < m; i++){
    cin >> v[0][i];
    v[0][i] *= 2;
  }

  for(int i = 1; i < n-1; i++){
    for(int j = 0; j < m; j++){
      cin >> v[i][j];

      if(j == 0 || j == m-1) v[i][j] *= 2;
    }
  }

  for(int i = 0; i < m; i++){
    cin >> v[n-1][i];
    v[n-1][i] *= 2;
  }

  int tot = 0;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      if(!vis[i][j] && v[i][j]){
        island = true;
        f(i, j);
        tot += island;
      }
    }
  }

  cout << tot;
}