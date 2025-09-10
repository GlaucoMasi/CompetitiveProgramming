#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

// conta(n) - conta(n-1 - v[n]) + conta(n-1)

// vector<int> v;

const int MOD = 1e9 + 7;

vector<int> memo;

int conta(int n, vector<int> &v){
  if(n < 0) return 1;

  if(memo[n] != -1)
    return memo[n];

  return memo[n] = (conta(n-1 - v[n], v) + conta(n-1, v)) % MOD;
}

int main() {
  // ottimizzazione input/output
  fin.tie(0);
  fin.sync_with_stdio(0);

  int n;
  fin >> n;

  vector<int> v(n);

  memo.resize(n, -1);

  for(int &i : v)
    fin >> i;

  fout << conta(n-1, v);
}