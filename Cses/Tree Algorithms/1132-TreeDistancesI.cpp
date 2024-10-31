#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> g;
vector<pair<int, int>> down;
vector<int> up;

void f1(int i, int fat){
  for(auto j : g[i]){
    if(j == fat) continue;

    f1(j, i);
    int t = down[j].first+1;

    if(t > down[i].first){
      down[i].second = down[i].first;
      down[i].first = t;
    }else if(t > down[i].second) down[i].second = t;
  }
}

void f2(int i, int fat){
  for(auto j : g[i]) if(j != fat) up[j] = max(up[i]+1, (down[i].first == down[j].first+1 ? down[i].second+1 : down[i].first+1));
  for(auto j : g[i]) if(j != fat) f2(j, i);
}

int main() {
  cin >> n;
  g.resize(n);
  up.resize(n);
  down.resize(n);

  for(int i = 0; i < n-1; i++){
    int a, b; cin >> a >> b;
    g[a-1].push_back(b-1);
    g[b-1].push_back(a-1);
  }

  f1(0, -1); f2(0, -1);
  for(int i = 0; i < n; i++) cout << max(up[i], down[i].first) << " ";
}