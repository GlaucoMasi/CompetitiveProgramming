#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
  int n; fin >> n;

  vector<long long> v(n);
  for(int i = 0; i < n; i++) fin >> v[i];
  
  sort(v.begin(), v.end(), greater<int>());
  
  long long best = -1e9;

  int i = 0;
  while(v[i] % 2 != 0 && i < n) i++;
  int y = i+1;
  while(v[y] % 2 != 0 && y < n) y++;
  best = ((v[i]+v[y]) % 2 == 0 && i < n && y < n) ? max(best, v[i] + v[y]) : best;

  int z = 0;
  while(v[z] % 2 != 1 && z < n) z++;
  int x = z+1;
  while(v[x] % 2 != 1 && x < n) x++;
  best = ((v[z]+v[x]) % 2 == 0 && x < n && z < n) ? max(best, v[z] + v[x]) : best;

  best = best != -1e9 ? best : -1;
  fout << best;
}