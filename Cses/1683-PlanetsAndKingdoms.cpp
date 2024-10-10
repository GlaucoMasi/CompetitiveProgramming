#include <bits/stdc++.h>
using namespace std;

int n, m;
int col = 0;
vector<vector<int>> g, inv;
vector<int> v, ans;

void f(int i){
  ans[i] = -1;

  for(auto j : g[i])
    if(ans[j] != -1) f(j);

  v.push_back(i);
}

void t(int i){
  ans[i] = col;

  for(auto j : inv[i])
    if(ans[j] == -1) t(j);
}

int main() {
  cin >> n >> m;

  ans.resize(n);

  g.resize(n);
  inv.resize(n);
  for(int i = 0; i < m; i++){
    int a, b; cin >> a >> b;
    a--; b--;

    g[a].push_back(b);
    inv[b].push_back(a);
  }

  for(int i = 0; i < n; i++){
    if(ans[i] != -1) f(i);
  }

  for(int i = v.size()-1; i >= 0; i--){
    if(ans[v[i]] == -1){
      col++;
      t(v[i]);
    }
  }

  cout << col << endl;
  for(auto i : ans) cout << i << " ";
}