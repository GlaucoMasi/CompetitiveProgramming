#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  int n, m; cin >> n >> m;
  vector<pair<int, int>> h(n);
  vector<int> t(m), p(m), ans(n);
  for(int i = 0; i < n; i++) cin >> h[i].first, h[i].second = i;
  for(auto &i : t) cin >> i;

  sort(h.begin(), h.end(), greater<>());
  for(auto [dish, idx] : h){
    pair<int, int> best = {1e9, -1};
    for(int i = 0; i < m; i++) best = min(best, {p[i]+t[i]*dish, i});
    p[best.second] = best.first;
    ans[idx] = best.second;
  }

  cout << *max_element(p.begin(), p.end()) << '\n';
  for(auto i : ans) cout << i << " ";
}