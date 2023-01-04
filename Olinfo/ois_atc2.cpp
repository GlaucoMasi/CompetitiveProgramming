#include <bits/stdc++.h>
using namespace std;

int main() {
  int n; cin >> n;

  vector<pair<int, int>> v;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      char c; cin >> c;
      if(c == 'T') v.push_back({i, j});
    }
  }

  vector<bool> b(v.size());
  vector<int> best(v.size(), 1e9);
  best[0] = 0; b[0] = 1;
  
  int node = 0, ans = 0;
  for(int k = 0; k < v.size()-1; k++){
    for(int i = 0; i < v.size(); i++){
      if(b[i]) continue;
      best[i] = min(best[i], (v[node].first-v[i].first)*(v[node].first-v[i].first) + (v[node].second-v[i].second)*(v[node].second-v[i].second));
    }

    pair<int, int> add = {1e9, 1e9};
    for(int i = 0; i < v.size(); i++){
      if(b[i]) continue;
      add = min(add, {best[i], i});
    }

    ans += add.first;
    node = add.second;
    b[node] = 1;
  }

  cout << ans;
}