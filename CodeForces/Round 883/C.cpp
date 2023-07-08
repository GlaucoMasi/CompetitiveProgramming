#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, m, h;
  cin >> n >> m >> h;

  pair<int, long long> ans;
  vector<pair<int, long long>> part;
  for(int i = 0; i < n; i++){
    vector<int> t(m);
    for(auto &i : t) cin >> i;
    sort(t.begin(), t.end());

    int time = 0, points = 0; long long pen = 0;
    for(auto i : t){
      time += i;

      if(time > h) break;

      points++;
      pen += time;
    }

    if(i == 0) ans = {points, -pen};
    part.push_back({points, -pen});
  }

  sort(part.begin(), part.end(), greater<>());
  for(int i = 0; i < n; i++){
    if(part[i] == ans){
      cout << i+1 << '\n';
      break;
    }
  }
}

int main() {
  int t; cin >> t;
  while(t--) solve();
}