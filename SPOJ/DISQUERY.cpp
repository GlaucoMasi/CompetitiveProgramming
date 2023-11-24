#include <bits/stdc++.h>
using namespace std;

int main() {
  int n; cin >> n;
  int LOG = log2(n)+1;
  vector<vector<pair<int, int>>> g(n);

  for(int i = 0; i < n-1; i++){
    int a, b, c; cin >> a >> b >> c;
    g[a-1].push_back({b-1, c});
    g[b-1].push_back({a-1, c});
  }

  vector<int> depth(n); depth[0] = 0;
  vector<vector<int>> fat(n, vector<int>(LOG, -1));
  vector<vector<pair<int, int>>> len(n, vector<pair<int, int>>(LOG, {1e9, -1}));
  function<void (int, int)> f = [&](int i, int prev) {
    for(int j = 1; j < LOG; j++){
      if(fat[i][j-1] == -1) break;
      fat[i][j] = fat[fat[i][j-1]][j-1];
      len[i][j] = {
        min(len[i][j-1].first, len[fat[i][j-1]][j-1].first),
        max(len[i][j-1].second, len[fat[i][j-1]][j-1].second)
      };
    }

    for(auto j : g[i]){
      if(j.first == prev) continue;

      fat[j.first][0] = i; len[j.first][0] = {j.second, j.second};
      depth[j.first] = depth[i]+1;
      f(j.first, i);
    }
  };

  f(0, -1);

  int q; cin >> q;
  while(q--){
    int a, b; cin >> a >> b; a--; b--;
    if(depth[a] < depth[b]) swap(a, b);

    pair<int, int> ans = {1e9, -1};

    int k = depth[a]-depth[b];
    for(int j = 0; j < LOG; j++){
      if(k & (1<<j)){
        ans = {min(ans.first, len[a][j].first), max(ans.second, len[a][j].second)};
        a = fat[a][j];
      }
    }

    if(a != b){
      for(int j = LOG-1; j >= 0; j--){
        if(fat[a][j] != fat[b][j]){
          ans = {min(ans.first, len[a][j].first), max(ans.second, len[a][j].second)};
          ans = {min(ans.first, len[b][j].first), max(ans.second, len[b][j].second)};
          a = fat[a][j];
          b = fat[b][j];
        }
      }

      ans = {min(ans.first, len[a][0].first), max(ans.second, len[a][0].second)};
      ans = {min(ans.first, len[b][0].first), max(ans.second, len[b][0].second)};
    }

    cout << ans.first << " " << ans.second << '\n';
  }
}