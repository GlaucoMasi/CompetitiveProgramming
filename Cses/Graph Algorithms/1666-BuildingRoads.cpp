#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> g;
vector<bool> vis;

void f(int i){
  vis[i] = 1;
  
  for(auto j : g[i]){
    if(!vis[j]) f(j);
  }
}

int main() {
  int n, m;
  cin >> n >> m;

  g.resize(n);
  vis.resize(n);
  
  int a, b;
  for(int i = 0; i < m; i++){
    cin >> a >> b;
    g[a-1].push_back(b-1);
    g[b-1].push_back(a-1);
  }

  vector<int> list;
  for(int i = 0; i < n; i++){
    if(!vis[i]){
      list.push_back(i);
      f(i);
    }
  }

  cout << list.size()-1 << endl;
  for(int i = 0; i < list.size()-1; i++){
    cout << list[i]+1 << " " << list[i+1]+1 << endl;
  }
}