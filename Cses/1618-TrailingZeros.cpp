#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  int ans = 0, n, p = 5; cin >> n;
  while(n/p) ans += n/p, p *= 5;
  cout << ans;
}