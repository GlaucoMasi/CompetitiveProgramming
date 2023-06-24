#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m; cin >> n >> m;
  vector<vector<long double>> dist(n, vector<long double>(n, 0));

  for(int i = 0; i < n; i++) dist[i][i] = 1;

  while(m--){
    int a, b, c; cin >> a >> b >> c;
    dist[a][b] = 1 - c/1000.0;
  }

  for(int k = 0; k < n; k++){
    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) dist[i][j] = max(dist[i][j], dist[i][k]*dist[k][j]);
  }

  pair<long double, pair<int, int>> ans; ans.first = 1e9;
  for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) if(i != j) ans = min(ans, {dist[i][j], {i, j}});
  cout << ans.second.first << " " << ans.second.second;
}