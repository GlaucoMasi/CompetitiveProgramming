#include <bits/stdc++.h>
using namespace std;

int n, ans;
vector<vector<int>> g;
vector<int> sz;

void f(int i, int p){
  int m = -1;
  for(auto j : g[i]) if(j != p){
    f(j, i);
    sz[i] += sz[j];
    m = max(m, sz[j]); 
  }

  if(p != -1) m = max(m, n-sz[i]);

  if(m <= n/2) ans = i;
}

int main() {
  cin >> n;

  g.resize(n); sz.resize(n, 1);
  for(int i = 0; i < n-1; i++){
    int a, b; cin >> a >> b;
    g[--a].push_back(--b);
    g[b].push_back(a);
  }

  f(0, -1);
  cout << ans+1;
}