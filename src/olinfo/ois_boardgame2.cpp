#include <bits/stdc++.h>
using namespace std;
#define watch(x) cout << (#x) << " is " << (x) << endl
ifstream fin("input.txt");
ofstream fout("output.txt");
//fout << "Case #" << t << ": ";

int n, m;
vector<vector<pair<int, long long>>> g;
vector<pair<long long, long long>> cost;
vector<bool> win, vis;

void f(int i){
  vis[i] = 1;

  for(auto [j, c] : g[i]){
    if(!vis[j]) f(j);
    if(!win[j]) win[i] = 1;
  }

  if(win[i]){
    cost[i] = {1e18, 1e18};
    for(auto [j, c] : g[i]) if(!win[j]) cost[i] = min(cost[i], {cost[j].second+c, cost[j].first});
  }else{
    cost[i] = {0, 0};
    for(auto [j, c] : g[i]) if(win[j] && cost[i].second < cost[j].first) cost[i] = {cost[j].second+c, cost[j].first};
  }
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  
  fin >> n >> m;
  g.resize(n);
  win.resize(n, 0);
  vis.resize(n);
  cost.resize(n);

  for(int i = 0; i < m; i++){
    int a, b, c; fin >> a >> b >> c;
    g[--a].push_back({--b, c});
  }

  f(0);
  fout << (win[0] ? "Alice\n" : "Bob\n");
  fout << (win[0] ? cost[0].first : cost[0].second);
}