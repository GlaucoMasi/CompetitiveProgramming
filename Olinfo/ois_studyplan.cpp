#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> h, t, topo, rem;
vector<bool> vis;
vector<vector<int>> g;

void f(int i){
  vis[i] = 1;
  for(auto j : g[i]) if(!vis[j]) f(j);
  topo.push_back(i);
}

int main() {
  cin >> n;
  h.resize(n); for(auto &i : h) cin >> i;

  g.resize(n);
  for(int i = 0; i < n; i++){
    int k; cin >> k;
    for(int j = 0; j < k; j++){
      int a; cin >> a;
      g[a].push_back(i);
    }
  }

  vis.resize(n);
  for(int i = 0; i < n; i++) if(!vis[i]) f(i);
  
  reverse(topo.begin(), topo.end());
  t.resize(n, 0);
  
  for(int i = 0; i < n; i++){
    int node = topo[i];
    for(auto j : g[node]) t[j] = max(t[j], t[node]+h[node]);
    t[node] += h[node];
  }

  rem.resize(n, 0);
  for(int i = n-1; i >= 0; i--){
    int node = topo[i];
    for(auto j : g[node]) rem[node] = max(rem[node], rem[j]);
    rem[node] += h[node];
  }

  int tot = *max_element(t.begin(), t.end());
  for(int i = 0; i < n; i++) cout << tot-rem[i] << " ";
}