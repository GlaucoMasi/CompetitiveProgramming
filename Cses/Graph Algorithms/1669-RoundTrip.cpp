#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> g;
vector<int> fat, status;

void f(int i, int father){
  if(status[i] != 0){
    vector<int> ans;
    ans.push_back(i);

    while(father != i){
      ans.push_back(father);
      father = fat[father];
    }

    ans.push_back(i);

    cout << ans.size() << endl;
    for(auto i : ans) cout << i+1 << " ";
    exit(0);
  }

  fat[i] = father;
  status[i] = 1;

  for(auto j : g[i]) 
    if(j != father) f(j, i);

  status[i] = 2;
}

int main() {
  cin >> n >> m;
  g.resize(n);
  fat.resize(n);
  status.resize(n);

  int a, b;
  for(int i = 0; i < m; i++){
    cin >> a >> b; a--; b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  for(int i = 0; i < n; i++)
    if(status[i] != 2) f(i, -1);

  cout << "IMPOSSIBLE";
}