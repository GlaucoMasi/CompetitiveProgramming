#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int n, m;
bool found = 0;
vector<vector<int>> g;
vector<int> fat, status;

void f(int i){
  if(status[i] == 2 || found) return;
  
  if(status[i] == 1){
    int t = i;
    vector<int> path;
    path.push_back(i);

    do{
      i = fat[i];
      path.push_back(i);
    }while(t != i);

    cout << path.size() << '\n';
    for(int i = path.size()-1; i >= 0; i--) cout << path[i]+1 << " ";

    found = 1;
    return;
  }

  status[i] = 1;
  for(auto j : g[i]) fat[j] = i, f(j);
  status[i] = 2;
}

int main() {
  cin >> n >> m;
  g.resize(n);
  status.resize(n);
  fat.resize(n, -1);

  for(int i = 0; i < m; i++){
    int a, b; cin >> a >> b;
    g[--a].push_back(--b);
  }

  for(int i = 0; i < n; i++) f(i);
  if(!found) cout << "IMPOSSIBLE";
}