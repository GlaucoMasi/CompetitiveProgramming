
#include <bits/stdc++.h>
using namespace std;

bool solve() {
  int n; cin >> n;
  int l, r;
  cin >> l; r = l;

  bool ok = 1;
  for(int i = 1; i < n; i++){
    int a; cin >> a;
    if(a != l-1 && a != r+1) ok = 0;
    l = min(l, a); r = max(r, a);
  }

  return ok;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int t = 1;
  cin >> t;
  while(t--) cout << (solve() ? "YES" : "NO") << '\n';
}