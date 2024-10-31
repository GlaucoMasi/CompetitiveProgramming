#include <bits/stdc++.h>
using namespace std;

int n, m;
int t = 0;
int col = -1;
vector<int> v, color;
vector<bool> check;
vector<vector<int>> g, p;

void f(int i){
  check[i] = 1;

  for(auto j : g[i])
    if(!check[j]) f(j);

  v.push_back(i);
}

void s(int i){
  color[i] = col;

  for(auto j : p[i])
    if(color[j] == -1) s(j);
}

int main() {
  cin >> n >> m;
  check.resize(n, 0);
  color.resize(n, -1);
  g.resize(n);
  p.resize(n);

  for(int i = 0; i < m; i++){
    int a, b; cin >> a >> b;
    a--; b--;

    g[a].push_back(b);
    p[b].push_back(a);
  }

  for(int i = 0; i < n; i++){
    if(!check[i]) f(i);
  }

  bool flag = 0;
  int ans;
  for(int i = v.size()-1; i >= 0; i--){
    if(color[v[i]] == -1){
      col++;
      if(col == 0) ans = v[i]+1;
      if(col == 1){
        flag = 1;
        cout << "NO" << endl;
        cout << v[i]+1 << " " << ans;
      }

      s(v[i]);
    }
  }

  if(!flag) cout << "YES";
}
