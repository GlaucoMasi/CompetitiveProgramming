#include <bits/stdc++.h>
using namespace std;

bool test(int n, int end, int t1, int t2, vector<vector<array<int, 3>>> &g, int off){
  vector<bool> prop(n);
  vector<long long> dist(n, 1e18);
  priority_queue<pair<long long, int>> pq;
  dist[0] = off; pq.push({-off, 0});

  while(!pq.empty()){
    int a = pq.top().second; pq.pop();

    if(a == n-1) break;
    if(prop[a]) continue;
    prop[a] = 1;

    for(auto [b, l1, l2] : g[a]){
      bool ok = (t2 <= dist[a] || t1 >= dist[a]+l1);

      if(!ok && dist[b] > dist[a]+l2){
        dist[b] = dist[a]+l2;
        pq.push({-dist[b], b});
      }

      if(dist[b] > l1 + (ok ? dist[a] : t2)){
        dist[b] = l1 + (ok ? dist[a] : t2); 
        pq.push({-dist[b], b});
      }
    }
  }

  return dist[n-1] <= end;
}

void solve() {
  int n, m;
  cin >> n >> m;

  int end, t1, t2;
  cin >> end >> t1 >> t2;

  vector<vector<array<int, 3>>> g(n);
  for(int i = 0; i < m; i++){
    int a, b, l1, l2;
    cin >> a >> b >> l1 >> l2;
    g[--a].push_back({--b, l1, l2});
    g[b].push_back({a, l1, l2});
  }

  int l = -1, r = end;
  while(l < r-1){
    int m = l + (r-l)/2;

    if(test(n, end, t1, t2, g, m)) l = m;
    else r = m;
  }

  cout << l << '\n';
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int t = 1;
  cin >> t;
  while(t--) solve();
}