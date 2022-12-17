#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> g;
vector<int> col;

void f(int i, int c){
  if(col[i] == c+1) return;

  if(col[i] != -1 && col[i] != c+1){
    cout << "IMPOSSIBLE";
    exit(0);
  }

  col[i] = c+1;

  for(auto j : g[i]) f(j, (c+1)%2);
}

int main() {
  cin >> n >> m;
  g.resize(n);
  col.resize(n, -1);

  int a, b;
  for(int i = 0; i < m; i++){
    cin >> a >> b;
    g[a-1].push_back(b-1);
    g[b-1].push_back(a-1);
  }

  for(int i = 0; i < n; i++){
    if(col[i] == -1) f(i, 0);
  }

  for(auto i : col) cout << i << " ";
}