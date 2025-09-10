#include <bits/stdc++.h>
using namespace std;
 
int n, m;
vector<vector<pair<int, int>>> g;
 
int main() {
  cin >> n >> m;
  g.resize(n);
 
  for(int i = 0; i < m; i++){
    int a, b, c;
    cin >> a >> b >> c;
    a--; b--;
 
    g[a].push_back({b, c});
  }
 
  priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
  vector<long long> d(n, 2e14);
  vector<bool> vis(n, 0);
  d[0] = 0;
  pq.push({0, 0});
 
  while(!pq.empty()){
    auto curr = pq.top(); pq.pop();
    
    if(vis[curr.second]) continue;
    vis[curr.second] = 1;
 
    for(auto i : g[curr.second]){
      if(d[i.first] > curr.first + i.second){
        d[i.first] = curr.first + i.second;
        pq.push({d[i.first], i.first});
      }
    }
  }
 
  for(auto i : d) cout << i << " ";
}