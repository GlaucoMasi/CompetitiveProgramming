#include <bits/stdc++.h>
using namespace std;

int main() {
  int n; cin >> n;
  vector<int> ans(n-1);
  vector<vector<pair<int, int>>> g(n);
  for(int i = 0; i < n-1; i++){
    int a, b; cin >> a >> b;
    g[a-1].push_back({b-1, i});
    g[b-1].push_back({a-1, i});
  }

  int LOG = log2(n)+1;
  vector<int> depth(n); depth[0] = 0;
  vector<vector<int>> fat(n, vector<int>(LOG, -1));
  function<void (int, int)> f = [&](int i, int prev) {
    for(int j = 1; j < LOG; j++){
      if(fat[i][j-1] == -1) break;
      fat[i][j] = fat[fat[i][j-1]][j-1];
    }

    for(auto j : g[i]){
      if(j.first != prev){
        depth[j.first] = depth[i]+1;
        fat[j.first][0] = i;
        f(j.first, i); 
      }
    }
  };

  f(0, -1);
  int q; cin >> q;
  vector<int> add(n);
  while(q--){
    int a, b;
    cin >> a >> b;
    a--; b--;

    add[a]++; add[b]++;
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

    add[a] -= 2;
  }

  function<void (int, int)> calc = [&](int i, int prev) {
    for(auto j : g[i]){
      if(j.first == prev) continue;

      calc(j.first, i);
      ans[j.second] = add[j.first];
      add[i] += add[j.first];
    }
  };

  calc(0, -1);
  for(auto i : ans) cout << i << " ";
}