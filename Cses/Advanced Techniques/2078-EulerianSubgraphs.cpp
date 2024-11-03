#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int nodes, edges;
vector<int> vis;
vector<vector<int>> g;

void f(int i){
  vis[i] = 1;
  edges += g[i].size();
  nodes++;
  for(auto j : g[i]) if(!vis[j]) f(j);
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  int n, m; cin >> n >> m;
  g.resize(n);
  vis.resize(n);

  for(int i = 0; i < m; i++){
    int a, b; cin >> a >> b;
    g[--a].push_back(--b);
    g[b].push_back(a);
  }

  int mod = 1e9+7;
  vector<long long> pows(m); pows[0] = 1;
  for(int i = 1; i < m; i++) pows[i] = (pows[i-1]*2)%mod;

  long long ans = 1;
  for(int i = 0; i < n; i++){
    if(vis[i]) continue;
    nodes = edges = 0;
    f(i);
    ans = (ans*pows[edges/2-nodes+1])%mod;
  }

  cout << ans;
}