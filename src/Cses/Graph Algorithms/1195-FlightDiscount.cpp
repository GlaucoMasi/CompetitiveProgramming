#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int n, m;
vector<long long> f(int i, vector<vector<pair<int, int>>> &g){
  vector<bool> prop(n);
  vector<long long> dist(n, 1e18);
  priority_queue<pair<long long, int>> pq;
  dist[i] = 0; pq.push({0, i});
  while(!pq.empty()){
    int i = pq.top().second; pq.pop();

    if(prop[i]) continue;
    prop[i] = 1;

    for(auto [j, l] : g[i]){
      if(dist[j] > dist[i]+l){
        dist[j] = dist[i]+l;
        pq.push({-dist[j], j});
      }
    }
  }

  return dist;
}

int main() {
  cin >> n >> m;
  vector<vector<pair<int, int>>> g(n), inv(n);

  for(int i = 0; i < m; i++){
    int a, b, c; cin >> a >> b >> c;
    g[--a].push_back({--b, c});
    inv[b].push_back({a, c});
  }

  long long ans = 1e18;
  vector<long long> a = f(0, g), b = f(n-1, inv);
  for(int i = 0; i < n; i++) for(auto [j, l] : g[i]) ans = min(ans, a[i]+b[j]+l/2);
  cout << ans;
}