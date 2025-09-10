#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int mod = 2011;
int n, m; string s;
vector<vector<int>> dp;
vector<int> precalc;

int calc(int match){
  if(precalc[match] != -1) return precalc[match];

  precalc[match] = 0;
  string news = s; news[match] = (s[match] == '1' ? '0' : '1');
  for(int i = 0; i <= match; i++){
    int t1 = -1, t2 = i-1;
    while(t2+1 <= match && s[t1+1] == news[t2+1]){ t1++; t2++; };
    if(t2 == match) precalc[match] = max(precalc[match], t1+1);
  }

  return precalc[match];
}

int f(int i, int match){
  if(match == m) return 0;
  if(i == n) return 1;
  if(dp[i][match] != -1) return dp[i][match];

  dp[i][match] = (f(i+1, match+1) + f(i+1, calc(match)))%2011;
  return dp[i][match];
}

int main() {
  fin >> m >> n >> s;
  precalc.resize(m, -1);
  dp.resize(n, vector<int>(m, -1));
  fout << f(0, 0);
}