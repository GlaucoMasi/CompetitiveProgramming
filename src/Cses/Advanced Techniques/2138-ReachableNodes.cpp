#include <bits/stdc++.h>
using namespace std;

vector<bool> done;
vector<bitset<50000>> v;
vector<vector<int>> g;

void f(int i){
  done[i] = 1;
  v[i].set(i, 1);

  for(auto j : g[i]){
    if(!done[j]) f(j);
    v[i] |= v[j];
  }
}

int main() {
  int n, m; cin >> n >> m;
  g.resize(n); v.resize(n, 0); done.resize(n);

  for(int i = 0; i < m; i++){
    int a, b; cin >> a >> b;
    g[a-1].push_back(b-1);
  }

  for(int i = 0; i < n; i++) if(!done[i]) f(i);
  for(auto i : v) cout << i.count() << " ";
}