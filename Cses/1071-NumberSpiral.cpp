#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

void solve() {
  long long x, y;
  cin >> x >> y;
  swap(x, y);
  
  long long lvl = max(x, y);
  long long start = (lvl-1)*(lvl-1);
  long long ord = x+(lvl-y);

  if(lvl%2) cout << start+ord << '\n';
  else cout << start+2LL*lvl-ord << '\n';
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int t; cin >> t;
  while(t--) solve();
}