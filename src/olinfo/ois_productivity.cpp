#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
  int n, m, e;
  fin >> n >> m >> e;

  int best = -1;

  for(int i = m; i <= n; i++){
    best = max(best, e - i*(e/i));
  }

  fout << best;
}