#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<pair<int, int>>> v;

vector<int> up, down;
void f(int i, int p){
  for(auto j : v[i]){
    if(j.first == p) continue;
    f(j.first, i);
    down[i] += down[j.first] + j.second;
  }
}

void g(int i, int p){
  for(auto j : v[i]){
    if(j.first == p) continue;
    up[j.first] = up[i] + !j.second + down[i] - (down[j.first] + j.second);
    g(j.first, i);
  }
}

int main() {
  int n; cin >> n;
  v.resize(n);
  
  up.resize(n, 0), down.resize(n, 0);

  for(int i = 0; i < n-1; i++){
    int a, b; cin >> a >> b; a--; b--;
    v[a].push_back({b, 0});
    v[b].push_back({a, 1});
  }

  f(0, -1);
  g(0, -1);
  
  pair<int, vector<int>> ans; ans.first = n;
  for(int i = 0; i < n; i++){
    if(down[i]+up[i] == ans.first) ans.second.push_back(i+1);
    else if(down[i]+up[i] < ans.first){
      ans.first = down[i]+up[i];
      ans.second = {i+1};
    }
  }

  sort(ans.second.begin(), ans.second.end());
  cout << ans.first << endl;
  for(auto &i : ans.second) cout << i << " ";
}