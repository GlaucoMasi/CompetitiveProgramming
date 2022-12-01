#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

vector<vector<int>> g;
vector<int> v;

int f(int i, int m){
  int ans = (v[i] > m);
  
  m = min(m, v[i]);

  for(auto j : g[i]) ans += f(j, m);

  return ans;
}

int main() {
  int n; fin >> n;
  v.resize(n);
  g.resize(n);

  int a;
  for(int i = 0; i < n; i++){
    fin >> v[i] >> a;
    if(a != -1) g[a].push_back(i); 
  }

  fout << f(0, 1e6+1);
}