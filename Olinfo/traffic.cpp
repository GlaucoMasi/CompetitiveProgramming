#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int n, best = 2e9;
vector<vector<int>> g;
vector<int> v, sub;

int calc(int i, int fat){
  sub[i] = v[i];

  for(auto j : g[i])
    if(j != fat) sub[i] += calc(j, i);

  return sub[i];
}

void f(int i, int fat){
  int ans = i == 0 ? 2e9 : sub[0] - sub[i];

  for(auto j : g[i])
    if(j != fat){
      f(j, i);
      ans = max(ans, sub[j]);
    }

  best = min(best, ans);
}

int main() {
  fin >> n;
  v.resize(n); for(auto &i : v) fin >> i;
  sub.resize(n);

  int a, b;  
  g.resize(n);
  for(int i = 0; i < n-1; i++){
    fin >> a >> b;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  calc(0, -1);

  f(0, -1);

  fout << best;
}