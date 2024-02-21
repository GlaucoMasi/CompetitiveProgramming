#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<vector<int>> g;
vector<int> path, ans;

void f(int i, int p){
  if(path.size() >= k) ans[i] = path[path.size()-k];

  path.push_back(i);
  for(auto j : g[i]) if(j != p) f(j, i);
  path.pop_back();
}

int main() {
  cin >> n >> k;
  g.resize(n); ans.resize(n, -1);

  for(int i = 0; i < n-1; i++){
    int a, b; cin >> a >> b;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  f(0, -1);
  for(auto i : ans) cout << i << " ";
}