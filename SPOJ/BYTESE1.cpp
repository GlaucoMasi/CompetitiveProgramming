#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, m; cin >> n >> m;
  vector<vector<int>> v(n, vector<int>(m));
  for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) cin >> v[i][j];

  int a, b, t;
  cin >> a >> b >> t;

  priority_queue<pair<int, pair<int, int>>> pq;
  vector<vector<int>> dist(n, vector<int>(m, 1e9));
  vector<vector<bool>> prop(n, vector<bool>(m));
  dist[0][0] = v[0][0]; pq.push({0, {0, 0}});
  while(!pq.empty()){
    int x = pq.top().second.first, y = pq.top().second.second; pq.pop();

    if(x == a-1 && y == b-1) break;

    if(prop[x][y]) continue;
    prop[x][y] = 1;

    if(x+1 < n && dist[x+1][y] > dist[x][y]+v[x+1][y]){
      dist[x+1][y] = dist[x][y]+v[x+1][y];
      pq.push({-dist[x+1][y], {x+1, y}});
    }

    if(x-1 >= 0 && dist[x-1][y] > dist[x][y]+v[x-1][y]){
      dist[x-1][y] = dist[x][y]+v[x-1][y];
      pq.push({-dist[x-1][y], {x-1, y}});
    }

    if(y+1 < m && dist[x][y+1] > dist[x][y]+v[x][y+1]){
      dist[x][y+1] = dist[x][y]+v[x][y+1];
      pq.push({-dist[x][y+1], {x, y+1}});
    }

    if(y-1 >= 0 && dist[x][y-1] > dist[x][y]+v[x][y-1]){
      dist[x][y-1] = dist[x][y]+v[x][y-1];
      pq.push({-dist[x][y-1], {x, y-1}});
    }
  }

  if(dist[a-1][b-1] <= t) cout << "YES\n" << t-dist[a-1][b-1] << '\n';
  else cout << "NO\n";
}

int main() {
  int t; cin >> t;
  while(t--) solve();
}