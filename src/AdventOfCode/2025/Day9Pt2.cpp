#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  vector<array<int, 2>> v;
  while(cin >> s) {
    int idx = s.find(',');
    v.push_back({
      stoi(s.substr(0, idx)),
      stoi(s.substr(idx+1))
    });
  }

  vector<int> diffX, diffY;
  diffX.push_back(-1); diffX.push_back(1e9);
  diffY.push_back(-1); diffY.push_back(1e9);
  for(auto [a, b] : v) diffX.push_back(a), diffY.push_back(b);
  sort(diffX.begin(), diffX.end());
  diffX.resize(unique(diffX.begin(), diffX.end())-diffX.begin());
  unordered_map<int, int> compX;
  for(int i = 0; i < diffX.size(); i++) compX[diffX[i]] = i;
  sort(diffY.begin(), diffY.end());
  diffY.resize(unique(diffY.begin(), diffY.end())-diffY.begin());
  unordered_map<int, int> compY;
  for(int i = 0; i < diffY.size(); i++) compY[diffY[i]] = i;
  
  int n = compX.size(), m = compY.size();
  vector<vector<int>> grid(n, vector<int>(m, 1));
  for(int i = 0; i < v.size(); i++) {
    auto [a, b] = v[i];
    auto [c, d] = v[(i+1)%v.size()];
    a = compX[a], b = compY[b], c = compX[c], d = compY[d];
    for(int x = min(a, c); x <= max(a, c); x++) for(int y = min(b, d); y <= max(b, d); y++) grid[x][y] = 2;
  }

  queue<pair<int, int>> q;
  for(int i = 0; i < n; i++) q.push({i, 0}), q.push({i, n-1});
  for(int i = 0; i < m; i++) q.push({0, i}), q.push({m-1, 0});
  while(!q.empty()) {
    auto [x, y] = q.front(); q.pop();
    if(x < 0 || y < 0 || x == n || y == n) continue;
    if(grid[x][y] != 1) continue;
    grid[x][y] = 0;
    q.push({x+1, y});
    q.push({x-1, y});
    q.push({x, y+1});
    q.push({x, y-1});
  }
  
  long long best = 0;
  for(int i = 0; i < v.size(); i++) {
    for(int j = i+1; j < v.size(); j++) {
      int a = compX[min(v[i][0], v[j][0])];
      int b = compY[min(v[i][1], v[j][1])];
      int c = compX[max(v[i][0], v[j][0])];
      int d = compY[max(v[i][1], v[j][1])];
      
      bool ok = 1;
      for(int x = a; x <= c; x++) for(int y = b; y <= d; y++) ok &= (grid[x][y] != 0);
      if(ok) best = max(best, 1LL*(abs(v[j][0]-v[i][0])+1)*(abs(v[j][1]-v[i][1])+1));
    }
  }

  cout << best;
}