#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int n, m;
int start;
vector<vector<int>> g;
vector<bool> vis;

int l = 0;
vector<int> path;

void f(int i){
  if(i == start && l > 1){
    fout << l << endl;

    for(int j = 0; j < l; j++){ 
      fout << path[j]+1;
      if(j != l-1) fout << " ";
    }

    exit(0);
  }

  if(vis[i]) return;
  vis[i] = 1;

  for(auto j : g[i]){
    path[l] = j;
    l++;
    f(j);
    l--;
  }
}

int main() {
  fin >> n >> m;
  g.resize(n);
  vis.resize(n, 0);
  path.resize(n);

  int a, b, c;
  for(int i = 0; i < m; i++){
    fin >> a >> b >> c;
    a--; b--;

    if(!c) continue;
    
    g[a].push_back(b);
    g[b].push_back(a);
  }

  for(int i = 0; i < n; i++) 
    if(!vis[i]){
      start = i;
      l = 0;
      f(i);
    }
}