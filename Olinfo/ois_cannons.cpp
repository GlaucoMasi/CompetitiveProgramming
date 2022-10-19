#include <bits/stdc++.h>
using namespace std;

int main() {
  int n; cin >> n;
  vector<int> v(n);
  for(auto &i : v) cin >> i;

  deque<int> dq;
  vector<long long> dist(n, 1e18);
  vector<bool> vis(n, 0);

  dq.push_back(0);
  dist[0] = 0;
  while(!dq.empty()){
    int node = dq.front(); dq.pop_front();
  
    if(vis[node]) continue;
    vis[node] = 1;

    if(dist[v[node]] > dist[node]){
      dist[v[node]] = dist[node];
      dq.push_front(v[node]);
    }

    if(node > 0 && dist[node-1] > dist[node]+1){
      dist[node-1] = dist[node]+1;
      dq.push_back(node-1);
    }

    if(node < n-1 && dist[node+1] > dist[node]+1){
      dist[node+1] = dist[node]+1;
      dq.push_back(node+1);
    }
  }

  cout << dist[n-1];
}