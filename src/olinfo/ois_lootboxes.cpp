#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

// c -> costo
// p -> probabilitÃ 

int x, n, p, c;
vector<int> best;

int main() {
  fin >> n >> x;

  best.resize(x + 5, 0);

  for(int i = 0; i < n; i++){ 
    fin >> p >> c;

    for(int y = x; y >= 0; y--){
      if(y >= c) best[y] = max(best[y], p + best[y - c]);
    }
  }

  fout << best[x];
}