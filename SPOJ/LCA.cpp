#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n;
  int LOG = log2(n)+1;
  vector<vector<int>> g(n);

  for(int i = 0; i < n; i++){
    int m; cin >> m;
    for(int j = 0; j < m; j++){
      int a; cin >> a;
      g[i].push_back(a-1);
    }
  }

  vector<int> depth(n); depth[0] = 0;
  vector<vector<int>> fat(n, vector<int>(LOG, -1));
  function<void (int)> f = [&](int i) {
    for(int j = 1; j < LOG; j++){
      if(fat[i][j-1] == -1) break;
      fat[i][j] = fat[fat[i][j-1]][j-1];
    }

    for(auto j : g[i]){
      fat[j][0] = i;
      depth[j] = depth[i]+1;
      f(j);
    }
  };

  f(0);

  int q; cin >> q;
  while(q--){
    int a, b; cin >> a >> b;
    a--; b--;
    if(depth[a] < depth[b]) swap(a, b);

    int k = depth[a]-depth[b];
    for(int j = 0; j < LOG; j++){
      if(k & (1<<j)) a = fat[a][j];
    }

    if(a == b) cout << a+1 << '\n';
    else{
      for(int j = LOG-1; j >= 0; j--){
        if(fat[a][j] != fat[b][j]){
          a = fat[a][j];
          b = fat[b][j];
        }
      }

      cout << fat[a][0]+1 << '\n';
    }
  }
}

int main() {
  int t; cin >> t;
  for(int i = 1; i <= t; i++){
    cout << "Case " << i << ":\n";
    solve();
  }
}