#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n;
  int LOG = log2(n)+1;
  vector<vector<pair<int, int>>> g(n);

  for(int i = 0; i < n-1; i++){
    int a, b, c; cin >> a >> b >> c;
    g[a-1].push_back({b-1, c});
    g[b-1].push_back({a-1, c});
  }

  vector<int> depth(n); depth[0] = 0;
  vector<vector<int>> fat(n, vector<int>(LOG, -1)), dist(n, vector<int>(LOG, 0));
  function<void (int, int)> f = [&](int i, int prev) {
    for(int j = 1; j < LOG; j++){
      if(fat[i][j-1] == -1) break;
      fat[i][j] = fat[fat[i][j-1]][j-1];
      dist[i][j] = dist[i][j-1] + dist[fat[i][j-1]][j-1];
    }

    for(auto j : g[i]){
      if(j.first == prev) continue;

      fat[j.first][0] = i; dist[j.first][0] = j.second;
      depth[j.first] = depth[i]+1;
      f(j.first, i);
    }
  };

  f(0, -1);

  while(1){
    string t; cin >> t;

    if(t == "DONE") break;

    if(t == "DIST"){
      int a, b; cin >> a >> b; a--; b--;
      if(depth[a] < depth[b]) swap(a, b);

      int ans = 0;

      int k = depth[a]-depth[b];
      for(int j = 0; j < LOG; j++){
        if(k & (1<<j)){
          ans += dist[a][j];
          a = fat[a][j];
        }
      }

      if(a == b) cout << ans << '\n';
      else{
        for(int j = LOG-1; j >= 0; j--){
          if(fat[a][j] != fat[b][j]){
            ans += dist[a][j]; a = fat[a][j];
            ans += dist[b][j]; b = fat[b][j];
          }
        }

        cout << ans + dist[a][0] + dist[b][0] << '\n';
      }
    }else if(t == "KTH"){
      int a, b, l; cin >> a >> b >> l; a--; b--;
      int v = a, u = b;
      if(depth[a] < depth[b]) swap(a, b);

      int k = depth[a]-depth[b];
      for(int j = 0; j < LOG; j++){
        if(k & (1<<j)) a = fat[a][j];
      }

      if(a != b){
        for(int j = LOG-1; j >= 0; j--){
          if(fat[a][j] != fat[b][j]){
            a = fat[a][j];
            b = fat[b][j];
          }
        }

        a = fat[a][0];
      }

      if(depth[v]-depth[a]+1 >= l){
        k = l-1;
        a = v;
      }else{
        k = depth[v]+depth[u]-2*depth[a]+1 - l;
        a = u;
      }

      for(int j = 0; j < LOG; j++){
        if(k & (1<<j)) a = fat[a][j];
      }

      cout << a+1 << '\n';
    }
  }
}

int main() {
  int t; cin >> t;
  while(t--) solve();
}