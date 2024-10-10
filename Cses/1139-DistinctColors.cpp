#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> col, ans;
vector<vector<int>> g;
vector<set<int>> v;

void f(int i, int p){
  for(auto j : g[i]) if(j != p) f(j, i);

  v[i].insert(col[i]);
  for(auto j : g[i]){
    if(j == p) continue;

    if(v[j].size() > v[i].size()) swap(v[i], v[j]);
    for(auto k : v[j]) v[i].insert(k);
  }

  ans[i] = v[i].size();
}

int main() {
  cin >> n;
  col.resize(n); for(auto &i : col) cin >> i;
  v.resize(n); ans.resize(n); g.resize(n);

  for(int i = 0; i < n-1; i++){
    int a, b; cin >> a >> b;
    g[--a].push_back(--b);
    g[b].push_back(a);
  }

  f(0, -1);
  for(auto i : ans) cout << i << " ";
}