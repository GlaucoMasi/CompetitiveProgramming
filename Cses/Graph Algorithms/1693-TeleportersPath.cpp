#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int n, m;
vector<int> path;
vector<vector<int>> g;

void f(int i){
  while(g[i].size()){
    int t = g[i].back();
    g[i].pop_back();
    f(t);
  }

  path.push_back(i);
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  cin >> n >> m;
  g.resize(n);

  vector<int> v(n);
  for(int i = 0; i < m; i++){
    int a, b; cin >> a >> b;
    g[--a].push_back(--b);
    v[a]++; v[b]--;
  }

  bool fail = (v[0] != 1 || v[n-1] != -1);
  for(int i = 1; i < n-1; i++) fail |= v[i];

  if(fail){
    cout << "IMPOSSIBLE";
    return 0;
  }
  
  f(0);
  if(path.size() != m+1) cout << "IMPOSSIBLE";
  else for(int i = m; i >= 0; i--) cout << path[i]+1 << " ";
}