#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n;
  int LOG = log2(n);

  int ans = 0;
  
  int sz = 1;
  while(2*sz <= n) sz *= 2;

  for(int i = 0; i <= LOG; i++){
    int uno;

    if(i == LOG) uno = n-sz+1;
    else{
      int period = 1<<(i+1);
      int count = (n-sz+1)/period;
      int in = n-sz+1 - period*count;
      int unos = period/2;
      uno = sz/2 + count*(1<<i) + max(0, (in - unos));
    }

    if(uno%2) ans += (1<<i);
    else ans += (1<<(i+1));
  }

  cout << ans << '\n';
}

int main() {
  int t; cin >> t;
  while(t--) solve();
}