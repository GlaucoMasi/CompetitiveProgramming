#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> g;
vector<long long> down, up, sz;

int sub(int i, int fat){
  for(auto j : g[i]) if(j != fat) sz[i] += sub(j, i);
  return sz[i];
}

void f1(int i, int fat){
  for(auto j : g[i]){
    if(j == fat) continue;

    f1(j, i);
    down[i] += down[j] + sz[j];
  }
}

void f2(int i, int fat){
  for(auto j : g[i]){
    if(j == fat) continue;

    up[j] = up[i]+n-sz[i] + down[i] - down[j]-sz[j] + sz[i]-sz[j];
    f2(j, i);
  }
}

int main() {
  cin >> n;
  g.resize(n);
  up.resize(n);
  down.resize(n);
  sz.resize(n, 1);

  for(int i = 0; i < n-1; i++){
    int a, b; cin >> a >> b;
    g[a-1].push_back(b-1);
    g[b-1].push_back(a-1);
  }

  sub(0, -1); f1(0, -1); f2(0, -1);
  for(int i = 0; i < n; i++) cout << up[i]+down[i] << " ";
}