#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int n, k, best = 0;
vector<int> v;

int main() {
  fin >> k >> n;
  v.resize(n);
  for(int i = 0; i < n; i++) fin >> v[i];

  for(int s = 0; s < n; s++){
    for(int t = 1; t <= k; t++){
      if(s + t < n)
        best = max(best, v[s+t] - v[s]);
    }
  }

  fout << best;
}