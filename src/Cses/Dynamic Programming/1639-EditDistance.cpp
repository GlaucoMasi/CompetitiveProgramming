#include <bits/stdc++.h>
using namespace std;

string a, b;
vector<vector<int>> memo;

int f(int i, int j){
  if(i == a.size()) return b.size()-j;
  if(j == b.size()) return a.size()-i;

  if(memo[i][j] != -1) return memo[i][j];

  int skip_a = f(i+1, j) + 1;
  int skip_b = f(i, j+1) + 1;
  int change = f(i+1, j+1) + (a[i] != b[j]);

  return memo[i][j] = min(min(skip_a, skip_b), change);
}

int main() {
  cin >> a >> b;
  if(b.size() < a.size()) swap(a, b);
  memo.resize(a.size(), vector<int>(b.size(), -1));

  cout << f(0, 0);
}