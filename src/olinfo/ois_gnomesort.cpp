#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  int n; cin >> n;
  vector<int> v(n); for(auto &i : v) cin >> i;
  
  vector<array<int, 2>> intervals;
  for(int i = 0; i < n; i++){
    if(v[v[i]] != i){
      cout << "NO";
      return 0;
    }else if(i < v[i]) intervals.push_back({i, v[i]});
  }
  
  set<pair<int, int>> s;
  vector<int> nxt(n, -1);
  for(int i = intervals.size()-1; i >= 0; i--){
    auto t = s.lower_bound({intervals[i][1], -1});
    if(t != s.begin()){
      auto [end, idx] = *prev(t);
      nxt[intervals[i][0]] = intervals[idx][0];
      s.erase(prev(t));
    }

    s.insert({intervals[i][1], i});
  }
  
  vector<bool> done(n);
  vector<vector<int>> ans;
  for(int i = 0; i < n; i++){
    if(done[i] || i == v[i]) continue;
    vector<int> dir, inv;
    dir.push_back(i);
    inv.push_back(v[i]);
    done[i] = done[v[i]] = 1;
    
    int j = i;
    while(nxt[j] != -1){
      j = nxt[j];
      dir.push_back(j);
      inv.push_back(v[j]);
      done[j] = done[v[j]] = 1;
    }

    for(int i = inv.size()-1; i >= 0; i--) dir.push_back(inv[i]);
    ans.push_back(dir);
  }

  cout << "YES\n" << ans.size() << '\n';
  for(auto i : ans){
    cout << i.size() << " ";
    for(auto j : i) cout << j << " ";
    cout << '\n';
  }
}