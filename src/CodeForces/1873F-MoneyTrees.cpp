#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, k; cin >> n >> k;
  vector<int> a(n), h(n);
  for(auto &i : a) cin >> i; for(auto &i : h) cin >> i;

  int best = 0;
  int l = 0, r = 0;
  long long tot = 0; 
  for(r; r < n; r++){
    if(r && h[r-1]%h[r]) l = r, tot = 0;

    tot += a[r];

    while(tot > k){
      tot -= a[l];
      l++;
    }

    best = max(best, r-l+1);
  }

  cout << best << '\n';
}

int main() {
  int t; cin >> t;
  while(t--) solve();
}