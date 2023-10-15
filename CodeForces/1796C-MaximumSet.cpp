#include <bits/stdc++.h>
using namespace std;

void solve() {
  long long l, r;
  int mod = 998244353;
  cin >> l >> r;

  long long t = 1, ans1 = 1;
  for(t; l*t*2 <= r; t *= 2, ans1++);

  int ans2 = (r/t-l+1)%mod;
  if(ans1 > 1 && l*t/2*3 <= r){
    t = t/2*3;
    ans2 = (ans2 + (r/t-l+1)*(ans1-1))%mod;
  }

  cout << ans1 << " " << ans2 << '\n';
}

int main() {
  int t; cin >> t;
  while(t--) solve();
}