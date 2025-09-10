#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
  int n, m;
  fin >> n >> m;

  vector<vector<pair<int, long long>>> g(n);
  int a, b; long long c;
  for(int i = 0; i < m; i++){
    fin >> a >> b >> c;
    a--; b--;

    g[a].push_back({b, c});
    g[b].push_back({a, c});
  }

  priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
  vector<long long> d(n, 1e18);
  vector<bool> vis(n);
  d[0] = 0;
  pq.push({0, 0});
  while(!pq.empty()){
    auto curr = pq.top();
    pq.pop();

    if(vis[curr.second]) continue;
    vis[curr.second] = 1;

    for(auto i : g[curr.second]){
      if(d[i.first] > curr.first + i.second){
        d[i.first] = curr.first + i.second;
        pq.push({d[i.first], i.first});
      }
    }
  }

  int tot = 0;
  for(int i = 0; i < n; i++){
    if(d[i] <= 10 * (i+1)) tot++;
  }

  fout << tot;
}