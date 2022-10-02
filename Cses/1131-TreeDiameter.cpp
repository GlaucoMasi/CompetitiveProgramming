#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> g;
vector<int> dist;

void f(int i, int fat, int d){
  dist[i] = d;

  for(auto j : g[i])
    if(j != fat) f(j, i, d+1);
}

int main() {
  int n; cin >> n;
  g.resize(n);
  dist.resize(n);
  
  int a, b;
  for(int i = 0; i < n-1; i++){
    cin >> a >> b; a--; b--;

    g[a].push_back(b);
    g[b].push_back(a);
  }

  f(0, -1, 0);
  f(max_element(dist.begin(), dist.end())-dist.begin(), -1, 0);
  cout << *max_element(dist.begin(), dist.end());
}