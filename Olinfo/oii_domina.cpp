#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int n, m;
vector<vector<int>> g;
vector<vector<bool>> beat;
vector<bool> vis;
set<int> coal;

void calc(int i, int j, int l) {
  if(!l) return;
  if(beat[i][j]) return;
  beat[i][j] = 1;

  for(auto k : g[j]) calc(i, k, l-1);
}

void add(int i){
  bool ok = 0;
  for(auto j : coal) if(beat[j][i]) ok = 1;
  if(ok) return;

  for(auto j : g[i]) if(coal.count(j)) coal.erase(j);
  coal.insert(i);

  for(auto j : g[i]){
    for(auto k : g[j]){
      for(auto t : g[k]) if(t < i) add(t);
    }
  }
}

int main() {
  fin >> n >> m;
  g.resize(n);
  beat.resize(n, vector<bool>(n, 0));
  vis.resize(n);

  for(int i = 0; i < m; i++){
    int a, b; fin >> a >> b;
    a--; b--;
    g[a].push_back(b);
  }

  for(int i = 0; i < n; i++) calc(i, i, 3);

  for(int i = 0; i < n; i++) add(i);
  for(int i = 0; i < n; i++) add(i);

  for(auto i : coal) fout << i+1 << " ";
}