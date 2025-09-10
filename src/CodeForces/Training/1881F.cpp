#include <bits/stdc++.h>
using namespace std;

vector<int> up;
vector<pair<int, int>> down1, down2;
vector<bool> mark;
vector<vector<int>> g;

void f1(int i, int p){
  for(auto j : g[i]){
    if(j == p) continue;
    f1(j, i);

    if(down1[j].first != -1){
      if(down1[i].first < down1[j].first+1){
        if(down1[i].second != j) down2[i] = down1[i];
        down1[i] = {down1[j].first+1, j};
      }else if(down2[i].first < down1[j].first+1 && down1[i].second != j) down2[i] = {down1[j].first+1, j};
    }

    if(down2[j].first != -1){
      if(down1[i].first < down2[j].first+1){
        if(down1[i].second != j) down2[i] = down1[i];
        down1[i] = {down2[j].first+1, j};
      }else if(down2[i].first < down2[j].first+1 && down1[i].second != j) down2[i] = {down1[j].first+1, j};
    }
  }
}

void f2(int i, int p){
  if(p != -1){
    if(up[p] != -1) up[i] = max(up[i], up[p]+1);

    if(down1[p].first != -1 && down1[p].second != i) up[i] = max(up[i], down1[p].first+1);
    else if(down2[p].first != -1 && down2[p].second != i) up[i] = max(up[i], down2[p].first+1);
  }

  for(auto j : g[i]) if(j != p) f2(j, i);
}

void solve() {
  int n, k; cin >> n >> k;
  g.clear(); g.resize(n);
  up.clear(); up.resize(n, -1);
  down1.clear(); down1.resize(n, {-1, -1});
  down2.clear(); down2.resize(n, {-1, -1});
  mark.resize(n, 0);

  for(int i = 0; i < k; i++){
    int a; cin >> a;
    mark[a-1] = 1;
    up[a-1] = 0;
    down1[a-1] = down2[a-1] = {0, -1};
  }

  for(int i = 0; i < n-1; i++){
    int a, b; cin >> a >> b;
    g[--a].push_back(--b);
    g[b].push_back(a);
  }

  f1(0, -1);
  f2(0, -1);

  int ans = 1e9;
  for(int i = 0; i < n; i++) ans = min(ans, max(up[i], down1[i].first));
  cout << ans << '\n';
}

int main() {
  int t; cin >> t;
  while(t--) solve();
}