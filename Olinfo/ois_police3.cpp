#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int n;
vector<int> v;
vector<int> memo;

int dp(int i){
  if(i >= n) return 0;
  if(memo[i] != -1) return memo[i];

  int salto = (i <= n-2) ? v[i+1] + dp(i+2) : 0;
  int aspetto = v[i] + dp(i+1);

  return memo[i] = min(salto, aspetto); 
}

int main() {
  fin >> n;
  v.resize(n);
  memo.resize(n, -1);

  for(auto &i : v) fin >> i;

  fout << dp(0);
}