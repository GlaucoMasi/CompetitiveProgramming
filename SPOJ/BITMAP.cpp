#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, m; cin >> n >> m;
  vector<vector<int>> dist(n, vector<int>(m, -1));
  queue<array<int, 3>> q;

  for(int i = 0; i < n; i++){
    string s; cin >> s;
    for(int j = 0; j < m; j++) if(s[j] == '1') q.push({i, j, 0});
  }

  while(!q.empty()){
    auto t = q.front(); q.pop();
    int x = t[0], y = t[1], d = t[2];
    
    if(dist[x][y] != -1) continue;
    dist[x][y] = d;

    if(x+1 < n) q.push({x+1, y, d+1});
    if(y+1 < m) q.push({x, y+1, d+1});
    if(x-1 >= 0) q.push({x-1, y, d+1});
    if(y-1 >= 0) q.push({x, y-1, d+1});
  }

  for(auto i : dist){
    for(auto j : i) cout << j << " ";
    cout << '\n';
  }
}

int main() {
  int t; cin >> t;
  while(t--) solve();
}