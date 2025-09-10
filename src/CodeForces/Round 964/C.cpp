#include <bits/stdc++.h>
using namespace std;

bool solve() {
  int n, s, m; cin >> n >> s >> m;
  vector<pair<int, int>> v;
  v.push_back({0, 0});
  while(n--){
    int a, b; cin >> a >> b;
    v.push_back({a, b});
  }
  v.push_back({m, m});

  for(int i = 0; i < v.size()-1; i++) if(v[i+1].first-v[i].second >= s) return 1;
  return 0;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int t = 1;
  cin >> t;
  while(t--) cout << (solve() ? "Yes" : "No") << '\n';
}