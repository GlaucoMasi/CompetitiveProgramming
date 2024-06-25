#include <bits/stdc++.h>
using namespace std;

vector<vector<pair<int, int>>> g;
void split(int u, int l, int r, int x, int y, int node, int cost, int type){
  if(l >= y || r <= x) return;
  if(l >= x && r <= y){
    if(type == 2) g[node].push_back({u, cost});
    else g[u+g.size()/2].push_back({node, cost});
    return;
  }

  split(2*u, l, (l+r)/2, x, y, node, cost, type);
  split(2*u+1, (l+r)/2, r, x, y, node, cost, type);
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n, q, s; cin >> n >> q >> s; s--;

  int sz = 1;
  while(sz < n) sz *= 2;
  g.resize(4*sz);

  for(int i = 1; i < sz; i++){
    g[i].push_back({2*i, 0});
    g[i].push_back({2*i+1, 0});

    g[2*i + 2*sz].push_back({i + 2*sz, 0});
    g[2*i+1 + 2*sz].push_back({i + 2*sz, 0});
  }

  for(int i = 0; i < sz; i++){
    g[sz+i].push_back({3*sz+i, 0});
    g[3*sz+i].push_back({sz+i, 0});
  }

  while(q--){
    int t; cin >> t;

    if(t == 1){
      int a, b, c; cin >> a >> b >> c;
      g[--a + sz].push_back({--b + sz, c});
    }else{
      int a, l, r, c; cin >> a >> l >> r >> c;
      split(1, 0, sz, --l, r, --a+sz, c, t);
    }
  }

  vector<bool> prop(4*sz);
  vector<long long> dist(4*sz, 1e18);
  priority_queue<pair<long long, int>> pq;
  dist[sz+s] = 0; pq.push({0, sz+s});
  while(!pq.empty()){
    int i = pq.top().second; pq.pop();
    
    if(prop[i]) continue;
    prop[i] = 1;

    for(auto [j, c] : g[i]){
      if(dist[j] > dist[i]+c){
        dist[j] = dist[i]+c;
        pq.push({-dist[j], j});
      }
    }
  }

  for(int i = 0; i < n; i++) cout << (dist[sz+i] < 1e18 ? dist[sz+i] : -1) << " ";
}