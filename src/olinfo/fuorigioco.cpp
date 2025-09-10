#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  int t, att, dif;
  fin >> t >> att >> dif;
  vector<array<double, 4>> atts(att), difs(dif);
  for(auto &i : atts) for(int k = 0; k < 4; k++) fin >> i[k];
  for(auto &i : difs) for(int k = 0; k < 4; k++) fin >> i[k];

  double low = 1e9, high = 1e9;
  for(auto [a, b, c, d] : atts) low = min(low, (d-b)*t/10+b);
  for(auto [a, b, c, d] : difs) high = min(high, (d-b)*t/10+b);

  fout << (low < high ? 'F' : 'R');
}