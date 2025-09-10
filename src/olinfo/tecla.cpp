#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int n, m;
vector<vector<int>> g;

vector<bool> par, disp;

bool f(int i, int l, vector<int> &v){
  if(l % 2 == 0) par[i] = true;
  else disp[i] = true;

  if(i == 0 && l % 2 == 1){
    fout << l << endl;
    for(int e = l; e > -1; e--) fout << v[e] << " ";
    return true;
  }

  for(auto e : g[i]){ 
    if(l % 2 == 1 && par[e] == true) continue;
    else if(l % 2 == 0 && disp[e] == true) continue;

    vector<int> copia(v);
    copia.push_back(e);

    if(f(e, l+1, copia)) return true;
  }

  return false;
}

int main() {
  fin >> n >> m;
  g.resize(n);
  par.resize(n);
  disp.resize(n);

  for(int i = 0; i < m; i++){
    int a, b;
    fin >> a >> b;

    g[a].push_back(b);
    g[b].push_back(a);
  }

  vector<int> v = {0};
  f(0, 0, v);
}