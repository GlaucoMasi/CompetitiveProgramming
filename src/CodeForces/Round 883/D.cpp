#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n;
  long double d, h; cin >> d >> h;
  
  long double ans = d*h;
  long double a; cin >> a;
  for(int i = 1; i < n; i++){
    long double b; cin >> b;

    ans += d*h;

    if(b-a < h) ans -= (d/h)*(b-a-h)*(b-a-h);

    a = b;
  }

  cout << setprecision(13) << ans/2 << '\n';
}

int main() {
  int t; cin >> t;
  while(t--) solve();
}