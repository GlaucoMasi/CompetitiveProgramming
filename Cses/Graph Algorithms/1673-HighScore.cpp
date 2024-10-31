#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> rev;
vector<bool> vis;

void bfs(int i){
  vis[i] = 1;

  for(auto j : rev[i])
    if(!vis[j]) bfs(j);
}

int main() {
  int n, m; cin >> n >> m;
  rev.resize(n);
  vis.resize(n);
  vector<long long> d(n, -1e18);
  d[0] = 0;

  int a, b, c;
  vector<pair<pair<int, int>, int>> e;
  while(m--){
    cin >> a >> b >> c;

    rev[b-1].push_back(a-1);
    e.push_back({{a-1, b-1}, c});
  }

  bfs(n-1);

  bool r, spec;
  int num = 0;
  while(1){
    r = 0; spec = 0;
    num++;

    for(auto i : e){
      if(d[i.first.first] == -1e18) continue;

      if(d[i.first.first]+i.second > d[i.first.second]){
        d[i.first.second] = d[i.first.first]+i.second;
        r = 1;

        if(vis[i.first.second]) spec = 1;
      }
    }
    
    if(num == n && spec) d[n-1] = -1;
    if(num == n || !r) break;
  }

  cout << d[n-1];
}