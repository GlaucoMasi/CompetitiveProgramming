#include <bits/stdc++.h>
using namespace std;

vector<vector<pair<int, int>>> g;
vector<long long> dist;
void dfs(int i){
  for(auto j : g[i]){
    if(dist[j.first] == -1){
      dist[j.first] = dist[i]+j.second;
      dfs(j.first);
    }
  }
}

int main() {
  int n, k;
  cin >> n >> k;

  long long tot = 0;
  g.resize(n);

  for(int i = 0; i < n-1; i++){
    int a, b, c;
    cin >> a >> b >> c;
    a--; b--;
    tot += c;
    g[a].push_back({b, c}); g[b].push_back({a, c});
  }

  if(k == 1) cout << tot*2;
  else{
    dist.resize(n, -1);
    dist[0] = 0; dfs(0);

    int a = max_element(dist.begin(), dist.end()) - dist.begin();
    dist.clear(); dist.resize(n, -1);
    dist[a] = 0; dfs(a);

    cout << 2*tot - *max_element(dist.begin(), dist.end());
  }
}