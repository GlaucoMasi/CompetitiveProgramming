#include <bits/stdc++.h>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int n, m;
int best = 0;
vector<vector<bool>> v;

void f(int a, int b, int tot){
  if(best > tot + (n-a-1) + (n * (m-b-1))) return;
  best = max(best, tot);

  if(a == n){
    a = 0; b++;
  }

  if(b == m) return;

  bool put = 1;

  if(a > 1)
    if(v[a-1][b] && v[a-2][b]) put = 0;
  
  if(b > 1)
    if(v[a][b-1] && v[a][b-2]) put = 0;

  if(a > 1 && b > 1)
    if(v[a-1][b-1] && v[a-2][b-2]) put = 0;

  if(a < n-2 && b > 1)
    if(v[a+1][b-1] && v[a+2][b-2]) put = 0;

  if(put){
    v[a][b] = 1;
    f(a+1, b, tot+1);
    v[a][b] = 0;
  }

  f(a+1, b, tot);
}

int main() {
  fin >> n >> m;

  v.resize(n, vector<bool>(m, 0));
  f(0, 0, 0);

  fout << best;
}