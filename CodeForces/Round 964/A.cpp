#include <bits/stdc++.h>
using namespace std;

void solve() {
  int a; cin >> a;
  cout << a/10+a%10 << '\n';
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int t = 1;
  cin >> t;
  while(t--) solve();
}