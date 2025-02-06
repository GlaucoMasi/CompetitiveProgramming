#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

void risolvi(int n, int m, int a[], int b[], int h[], long long ans[]){
  vector<vector<pair<int, int>>> g(n);

  for(int i = 0; i < m; i++){
    g[a[i]-1].push_back({b[i]-1, h[i]});
    g[b[i]-1].push_back({a[i]-1, h[i]});
  }

  int done = 1;
  vector<bool> vis(n);
  vector<int> fat(n), height(n), area(n, 1);
  vector<priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>>> e(n);
  
  int curr = 0;
  fat[0] = -1; height[0] = 1e9;
  for(auto [a, b] : g[0]) e[0].push({b, a});
  e[0].push({1e9, -1});
  vis[0] = 1; ans[1] = 0;

  while(done < n){
    if(e[curr].top().second == fat[curr]){
      e[curr].pop();

      if(e[fat[curr]].size() < e[curr].size()) swap(e[fat[curr]], e[curr]);
      while(!e[curr].empty()) e[fat[curr]].push(e[curr].top()), e[curr].pop();

      area[fat[curr]] += area[curr];
      curr = fat[curr];
    }else{
      auto [h, node] = e[curr].top(); e[curr].pop();

      if(vis[node]) continue;
      vis[node] = 1; done++;
      ans[node+1] = ans[curr+1]+(long long)area[curr]*h;

      fat[node] = curr;
      height[node] = h;

      for(auto [a, b] : g[node]) e[node].push({b, a});
      e[node].push({h, curr});

      curr = node;
    }
  }
}