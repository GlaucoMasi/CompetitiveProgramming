#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  
  int n, m;
  cin >> n >> m;
  vector<int> col(n);
  vector<vector<int>> comps(n);
  vector<vector<int>> diff(n), same(n);
  vector<pair<int, int>> reached(n, {-1, -1});

  for(int i = 0; i < n; i++){
    cin >> col[i];
    comps[col[i]].push_back(i);
  }

  for(int i = 0; i < m; i++){
    int a, b; cin >> a >> b;
    if(col[a] != col[b]){
      diff[a].push_back(b);
      diff[b].push_back(a);
    }else{
      same[a].push_back(b);
      same[b].push_back(a);
    }
  }

  int ans = 1e9;
  queue<int> in;
  for(int i = 0; i < n; i++){
    for(auto x : comps[i]){
      for(auto j : diff[x]){
        if(reached[x].first == -1){
          reached[x] = {col[j], 1};
          in.push(x);
        }else if(reached[x].first != col[j]) ans = min(ans, 2);
      }
    }

    while(!in.empty()){
      auto x = in.front(); in.pop();
      int c = reached[x].first, d = reached[x].second;
      if(d >= ans) continue;

      for(auto j : same[x]){
        if(reached[j].first == -1){
          reached[j] = {c, d+1};
          in.push(j);
        }else if(reached[j].first != c) ans = min(ans, reached[j].second+d+1);
      }
    }
  }

  cout << (ans == 1e9 ? -1 : ans);
}