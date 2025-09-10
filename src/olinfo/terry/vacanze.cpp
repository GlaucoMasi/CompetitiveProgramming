#include <bits/stdc++.h>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int n, m, conto, start;
vector<vector<int>> g;
vector<vector<bool>> tab;

void count(int i, int father, int l){
  if(l > 4) return;
  if(i == start && l == 4){
    conto++;
    return;
  }

  for(auto j : g[i]){
    if(j == father) continue;
    if(tab[father][j] || tab[j][father]) continue;

    count(j, i, l+1);
  }
}

int main() {
  int t; fin >> t;

  for(int tt = 1; tt <= t; tt++){
    fin >> n >> m;
    conto = 0;

    g.clear();
    tab.clear();
    g.resize(n);
    tab.resize(n+1, vector<bool>(n+1));

    for(int i = 0; i < m; i++){
      int a, b; fin >> a >> b;

      g[a].push_back(b);
      g[b].push_back(a);

      tab[a][b] = 1;
      tab[b][a] = 1;
    }

    for(int i = 0; i < n; i++){
      start = i;
      count(i, n, 0);
    }

    fout << "Case #" << tt << ": " << conto / 8 << endl;
  }
}