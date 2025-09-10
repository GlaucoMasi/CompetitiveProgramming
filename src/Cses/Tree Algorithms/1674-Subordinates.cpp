#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> g;
vector<int> sub;

int f(int i){
  for(auto j : g[i]) sub[i] += f(j);

  return sub[i]+1;
}

int main() {
  int n; cin >> n;
  g.resize(n);
  sub.resize(n, 0);
  
  int a;
  for(int i = 1; i < n; i++){
    cin >> a;
    g[a-1].push_back(i);
  }

  f(0);
  for(auto i : sub) cout << i << " ";
}