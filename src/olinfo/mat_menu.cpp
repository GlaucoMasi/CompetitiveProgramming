#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int n, k;
vector<int> v;
vector<vector<int>> memo;

int f(int i, int k){
  if(i == n || k == 0) return 0;

  if(memo[i][k] != -1) return memo[i][k];

  int prendo = (k >= v[i]) ? f(i+1, k - v[i]) + v[i] : 0;

  return memo[i][k] = max(prendo, f(i+1, k));
}

void stampa(int i, int k){
  if(i == n || k == 0) return;

  if(k < v[i]) return stampa(i+1, k);

  int prendo = f(i+1, k - v[i]) + v[i];
  int nonprendo = f(i+1, k);

  if(prendo > nonprendo){
    fout << v[i] << endl;
    return stampa(i+1, k - v[i]);
  } else return stampa(i+1, k);
}

int main() {
  fin >> n >> k;

  v.resize(n);
  memo.resize(n, vector<int>(k+1, -1));
  for(int i = 0; i < n; i++) fin >> v[i];

  for(int i = n-1; i >= 0; i--)
    for(int j = 0; j <= k; j++)
      f(i, j);

  stampa(0, k);
}