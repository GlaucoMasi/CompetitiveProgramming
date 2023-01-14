#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m, l;
  cin >> n >> m >> l;

  int a, b;
  vector<vector<int>> g(n);
  while(m--){
    cin >> a >> b;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  vector<int> occ(n, -1);
  for(int i = 0; i < l; i++){
    cin >> a;
    occ[a] = i;
  }

  queue<pair<int, int>> q;
  vector<bool> vis(n);
  q.push({0, 0});
  while(!q.empty()){
    int i = q.front().first, d = q.front().second; q.pop();

    if(i == n-1){
      cout << d;
      break;
    }

    if(vis[i]) continue;
    vis[i] = 1;

    for(auto j : g[i]){
      if(occ[j] != (d+1)%l) q.push({j, d+1});
      else if(occ[i] != (d+1)%l){
        vis[i] = 0;
        q.push({i, d+1});
      }
    }
  }
}