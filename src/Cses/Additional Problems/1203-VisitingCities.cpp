#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
uniform_int_distribution<long long> distr((long long)1e9, (long long)2e9);

const long long mod1 = distr(rng);
const long long mod2 = distr(rng);

vector<array<long long, 3>> dijkstra(vector<vector<pair<int, int>>> g, int start){
  int n = g.size();
  vector<bool> prop(n);
  vector<array<long long, 3>> dist(n, {(long long)1e18, 0, 0});
  priority_queue<pair<long long, int>> pq;
  
  dist[start] = {0, 1}; pq.push({0, start});
  while(!pq.empty()){
    int i = pq.top().second; pq.pop();

    if(prop[i]) continue;
    prop[i] = 1;

    for(auto [j, l] : g[i]){
      long long nxt = dist[i][0]+l;
      if(dist[j][0] == nxt){
        dist[j][1] = (dist[j][1]+dist[i][1])%mod1;
        dist[j][2] = (dist[j][2]+dist[i][2])%mod1;
      }else if(dist[j][0] > nxt){
        dist[j][0] = nxt;
        dist[j][1] = dist[i][1];
        dist[j][2] = dist[i][2];
        pq.push({-dist[j][0], j});
      }
    }
  }

  return dist;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  int n, m; cin >> n >> m;
  vector<vector<pair<int, int>>> g(n), inv(n);

  for(int i = 0; i < m; i++){
    int a, b, c; cin >> a >> b >> c;
    g[--a].push_back({--b, c});
    inv[b].push_back({a, c});
  }

  auto forw = dijkstra(g, 0), back = dijkstra(inv, n-1);

  vector<int> ans;
  for(int i = 0; i < n; i++){
    long long tot1 = (forw[i][1]*back[i][1])%mod1;
    long long tot2 = (forw[i][2]*back[i][2])%mod2;
    if(forw[i][0] + back[i][0] == forw[n-1][0] && tot1 == forw[n-1][1] && tot2 == forw[n-1][2]) ans.push_back(i);
  }

  cout << ans.size() << '\n';
  for(auto i : ans) cout << i+1 << " ";
}