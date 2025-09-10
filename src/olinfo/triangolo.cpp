#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

// prima coordinata -> colonna
// seconda coordinata -> riga

int main() {
  int n;
  fin >> n;
  
  vector<vector<int> > v(n, vector<int>(n));
  vector<vector<int> > ans(n, vector<int>(n, 1e9));

  for(int i = 0; i < n; i++)
    for(int y = 0; y <= i; y++)
      fin >> v[i][y];
  
  for(int i = 0; i < n; i++) ans[n-1][i] = v[n-1][i];

  for(int y = n-2; y >= 0; y--)
    for(int x = y; x >= 0; x--)
      ans[y][x] = v[y][x] + max(ans[y+1][x], ans[y+1][x+1]);

  fout << ans[0][0];
}