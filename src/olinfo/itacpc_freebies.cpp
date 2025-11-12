#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int m; cin >> m;
  vector<int> booth(m); for(auto &i : booth) cin >> i;
  sort(booth.begin(), booth.end());

  int x, y; cin >> x >> y;

  int n; cin >> n;
  vector<vector<int>> reach(m);
  for(int i = 0; i < n; i++) {
    int a, b; cin >> a >> b;
    int idx = upper_bound(booth.begin(), booth.end(), b) - booth.begin();
    int reach1 = idx == 0 ? 1e9 : b-booth[idx-1], reach2 = idx == m ? 1e9 : booth[idx]-b;
    reach[reach1 <= reach2 ? idx-1 : idx].push_back(min(reach1, reach2) + a);
  }

  int best = 1e9;
  for(auto &i : reach) sort(i.begin(), i.end());
  for(int i = 0; i < m; i++) {
    int time = abs(booth[i]-y) + x;
    best = min(best, (int)(upper_bound(reach[i].begin(), reach[i].end(), time) - reach[i].begin()));
  }

  cout << best;
}