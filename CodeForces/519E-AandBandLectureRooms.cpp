#include <bits/stdc++.h>
using namespace std;

int main() {
  int n; cin >> n;
  int LOG = log2(n)+1;
  vector<vector<int>> g(n);

  for(int i = 0; i < n-1; i++){
    int a, b; cin >> a >> b;
    g[a-1].push_back(b-1);
    g[b-1].push_back(a-1);
  }

  vector<int> sz(n, 1);
  vector<int> depth(n); depth[0] = 1;
  vector<vector<int>> fat(n, vector<int>(LOG, -1));
  function <void (int, int)> f = [&](int i, int prev){
    for(int j = 1; j < LOG; j++){
      if(fat[i][j-1] == -1) break;
      fat[i][j] = fat[fat[i][j-1]][j-1];
    }

    for(auto j : g[i]){
      if(j != prev){
        depth[j] = depth[i]+1;
        fat[j][0] = i;
        f(j, i);
        sz[i] += sz[j];
      }
    }
  };

  auto up = [&](int a, int k){
    for(int i = 0; i < LOG; i++){
      if(k & (1<<i)) a = fat[a][i];
    }

    return a;
  };

  auto lca = [&](int a, int b){
    a = up(a, depth[a]-depth[b]);
    array<int, 3> ans;

    if(a != b){
      for(int i = LOG-1; i >= 0; i--){
        if(fat[a][i] != fat[b][i]){
          a = fat[a][i];
          b = fat[b][i];
        }
      }

      return ans = {fat[a][0], a, b};
    }

    return ans = {a, -1, -1};
  };

  f(0, -1);

  int q; cin >> q;
  while(q--){
    int a, b;
    cin >> a >> b; a--; b--;
    if(depth[a] < depth[b]) swap(a, b);

    auto v = lca(a, b);

    if(a == b) cout << n << '\n';
    else if(depth[a] == depth[b]) cout << n-sz[v[1]]-sz[v[2]] << '\n';
    else{
      int len = depth[a]+depth[b]-2*depth[v[0]]+1;

      if(len%2){
        a = up(a, len/2-1);
        cout << sz[fat[a][0]] - sz[a] << '\n';
      }else cout << 0 << '\n';
    }
  }
}