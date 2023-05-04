#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m, k;
  cin >> n >> m >> k;

  vector<vector<int>> g(n);
  for(int i = 0; i < m; i++){
    int a, b; cin >> a >> b;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  for(int i = 0; i < n; i++) g[i].push_back(i);

  vector<vector<bool>> occ(n, vector<bool>(420));
  for(int i = 0; i < k; i++){
    int l; cin >> l;
    vector<int> v(l);
    for(auto &j : v) cin >> j;

    for(int j = 0; j < 420; j++) occ[v[j%l]][j] = 1;
  }

  vector<vector<int>> d(n, vector<int>(420, 1e9));
  queue<array<int, 2>> q;
  q.push({0, 0});
  d[0][0] = 0;
  while(!q.empty()){
    int node = q.front()[0], t = q.front()[1]; q.pop();

    if(node == n-1){
      cout << d[node][t%420];
      return 0;
    }

    for(auto i : g[node]) if(d[i][(t+1)%420] == 1e9 && !occ[i][(t+1)%420]){
      d[i][(t+1)%420] = d[node][t%420]+1;
      q.push({i, t+1});
    }
  }

  cout << "-1";
}