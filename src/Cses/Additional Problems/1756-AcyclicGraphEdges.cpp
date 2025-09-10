#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int n, m;
vector<vector<int>> g;
vector<int> depth;

void f(int i, int p){
  if(p != -1) depth[i] = depth[p]+1;
  for(auto j : g[i]) if(!depth[j]) f(j, i);
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  cin >> n >> m;
  g.resize(n);
  depth.resize(n);

  vector<pair<int, int>> edges;
  for(int i = 0; i < m; i++){
    int a, b; cin >> a >> b;
    g[--a].push_back(--b);
    g[b].push_back(a);
    edges.push_back({a, b});
  }

  for(int i = 0; i < n; i++){
    if(depth[i]) continue;
    depth[i] = 1;
    f(i, -1);
  }

  for(auto [a, b] : edges){
    if(depth[b] < depth[a]) swap(a, b);
    cout << a+1 << " " << b+1 << '\n';
  }
}