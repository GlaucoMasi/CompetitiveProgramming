#include <bits/stdc++.h>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

// 1 right, 2 left, 3 right vincolante, 4 left vincolante

int n;
vector<int> l, r;
vector<vector<long long>> memo;

long long f(int i, int last){
  if(i == n) return 0;
  if(memo[i][last] != -1) return memo[i][last];

  long long ans = 0;
  if(last == 1) ans = min(f(i+1, 3) + r[i], f(i+1, 2) + l[i]);
  if(last == 2) ans = min(f(i+1, 1) + r[i], f(i+1, 4) + l[i]);
  if(last == 3) ans = f(i+1, 2) + l[i];
  if(last == 4) ans = f(i+1, 1) + r[i];

  return memo[i][last] = ans;
}

int main() {
  int t; fin >> t;

  for(int tt = 1; tt <= t; tt++){
    fin >> n;
    l.clear();
    l.resize(n);
    r.clear();
    r.resize(n);
    memo.clear();
    memo.resize(n, vector<long long>(5, -1));

    for(int i = 0; i < n; i++) fin >> l[i] >> r[i];

    fout << "Case #" << tt << ": " << min(f(0, 1), f(0, 2)) << endl;
  }
}