#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  int n, m, k; cin >> n >> m >> k;
  vector<vector<pair<int, int>>> g(n);

  for(int i = 0; i < m; i++){
    int a, b, c; cin >> a >> b >> c;
    g[--a].push_back({--b, c});
  }

  vector<int> prop(n, k);
  vector<vector<long long>> dist(n);
  priority_queue<pair<long long, int>> pq; pq.push({0, 0});
  while(!pq.empty()){
    auto [d, i] = pq.top(); pq.pop();

    if(!prop[i]) continue;
    prop[i]--;

    dist[i].push_back(-d);
    for(auto [j, l] : g[i]) pq.push({d-l, j});
  }

  for(auto i : dist[n-1]) cout << i << " ";
}