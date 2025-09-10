#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int n;
bool first = false;
vector<int> v;
vector<vector<int>> memo;

int f(int i, int first){
  if(i >= n) return 0;

  if(memo[i][first] != -1) return memo[i][first];

  int faccio = (i != n-1 && i != 0) ? f(i + 2, first) + v[i] : 0;

  if(i == 0) faccio = f(i + 2, 1) + v[i];
  if(i == n-1) faccio = (first == 0) ? f(i + 2, first) + v[i] : 0;

  int nonfaccio = f(i + 1, first);

  return memo[i][first] = max(faccio, nonfaccio);
}

int main() {
  fin.tie(0);
  fin.sync_with_stdio(0);

  fin >> n;
  v.resize(n);
  memo.resize(n, vector<int> (2, -1));
  for(int i = 0; i < n; i++) fin >> v[i];

  fout << f(0, 0);
}