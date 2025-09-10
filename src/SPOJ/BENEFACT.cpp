#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n;
  vector<vector<pair<int, int>>> g(n);
  pair<int, int> ans = {-1, 0};

  for(int i = 0; i < n-1; i++){
    int a, b, c;
    cin >> a >> b >> c;
    g[a-1].push_back({b-1, c});
    g[b-1].push_back({a-1, c});
  }

  function<void (int, int, int)> f = [&](int i, int p, int l) {
    ans = max(ans, {l, i});
    for(auto j : g[i]) if(j.first != p) f(j.first, i, l+j.second);
  };

  f(0, -1, 0);
  int t = ans.second; ans = {-1, 0};
  f(t, -1, 0);
  cout << ans.first << '\n';
}

int main() {
  int t; cin >> t;
  while(t--) solve();
}