#include <bits/stdc++.h>
using namespace std;

int n, m;
int num = 0;
vector<vector<bool>> vis;

void f(int x, int y){
  vis[x][y] = 1;

  for(int i = -1; i < 2; i++){
    for(int j = -1; j < 2; j++){
      if(i == j || i == -j) continue;
      if(x+i == -1 || x+i == n || y+j == -1 || y+j == m) continue;

      if(!vis[x+i][y+j]) f(x+i, y+j);
    }
  }
}

int main() {
  cin >> n >> m;
  vis.resize(n, vector<bool>(m, 0));

  for(int i = 0; i < n; i++){
    string s; cin >> s;
    for(int j = 0; j < m; j++){
      char c = s[j];

      if(c == '#') vis[i][j] = 1;
    }
  }

  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      if(!vis[i][j]){
        num++;
        f(i, j);
      }
    }
  }

  cout << num;
}