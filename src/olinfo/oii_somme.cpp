#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int n;
vector<int> v;
vector<vector<int>> memo;

int dp(int l, int r){
  if(memo[l][r] != -1) return memo[l][r];
  if(l == r) return 0;

  int ans = 2e9;
  for(int i = l; i < r; i++){
    int left = dp(l, i);
    int right = dp(i+1, r);
    ans = min(ans, max(left, right));
  }

  int somma = abs(v[r] - (l ? v[l-1] : 0));
  return memo[l][r] = max(somma, ans);
}

int main() {
  fin >> n;
  v.resize(n);
  memo.resize(n, vector<int>(n, -1));
  for(int &i : v) fin >> i;

  partial_sum(v.begin(), v.end(), v.begin());
  fout << dp(0, n-1);
}