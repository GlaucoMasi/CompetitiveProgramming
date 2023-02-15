#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int n, m, p;
vector<vector<int>> g;
vector<double> arrive;
vector<int> top;

void f(int i){
  arrive[i] = 0;

  for(auto j : g[i]) if(arrive[j]) f(j);

  top.push_back(i);
}

int main() {
  cin >> n >> m >> p;
  g.resize(n);
  arrive.resize(n, -1);

  int a, b;
  for(int i = 0; i < m; i++){
    cin >> a >> b;
    g[a].push_back(b);
  }
  
  f(0);

  pair<float, int> ans = {0, 0}; arrive[0] = 1;
  for(int i = n-1; i >= 0; i--){
    if(g[top[i]].size() == 0) ans = max(ans, {arrive[top[i]], top[i]});
    else for(auto j : g[top[i]]) arrive[j] += arrive[top[i]]/g[top[i]].size();
  }

  cout << ans.second;
}