#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> g;
vector<int> ans;

int f(int i, int p){
  int big = 0, tot = 1;

  for(auto j : g[i]){
    if(j == p) continue;

    int a = f(j, i);
    big = max(big, a); tot += a;
  }

  big = max(big, n-tot);
  if(big <= n/2) ans.push_back(i);

  return tot;
}

int main() {
  cin >> n;
  g.resize(n);

  for(int i = 0; i < n-1; i++){
    int a, b; cin >> a >> b;
    a--; b--;

    g[a].push_back(b);
    g[b].push_back(a);
  }

  f(0, -1);
  sort(ans.begin(), ans.end());
  for(auto i : ans) cout << i+1 << endl;
}