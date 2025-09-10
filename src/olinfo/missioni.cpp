#include <bits/stdc++.h>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int n;
vector<pair<int, int>> v;
vector<vector<int>> memo;

int best(int d, int i){
  if(d < 1) return 0;
  if(i < 0) return 0;

  if(memo[d][i] != -1) return memo[d][i];

  int faccio = 0;
  if(d <= v[i].first && d >= v[i].second) faccio = best(d-v[i].second, i-1) + 1;

  int saltogg = best(d-1, i);
  int saltomis = best(d, i-1);

  return memo[d][i] = max(faccio, max(saltogg, saltomis));
}

int main() {
  fin >> n;

  v.resize(n);
  memo.resize(366, vector<int>(n, -1));
  for(auto &i : v) fin >> i.second >> i.first;

  fout << best(365, n-1);
}