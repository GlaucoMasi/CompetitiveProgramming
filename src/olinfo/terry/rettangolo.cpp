#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

void solve(int k) {
  int a1, a2, b1, b2, c1, c2;
  fin >> a1 >> a2 >> b1 >> b2 >> c1 >> c2;

  int ans1, ans2;

  if(a1 == b1) ans1 = c1;
  else if(a1 == c1) ans1 = b1;
  else ans1 = a1;

  if(a2 == b2) ans2 = c2;
  else if(a2 == c2) ans2 = b2;
  else ans2 = a2;

  fout << "Case #" << k << ": " << ans1 << " " << ans2 << endl;
}

int main() {
  int t; fin >> t;
  for(int i = 1; i <= t; i++) solve(i);
}