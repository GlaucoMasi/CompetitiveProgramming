#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  int n, k; fin >> n >> k;
  vector<int> v(n); for(auto &i : v) fin >> i;
  sort(v.begin(), v.end());

  int best = 1e9;
  for(int i = 0; i+k-1 < n; i++) best = min(best, v[i+k-1]-v[i]);

  fout << best;
}