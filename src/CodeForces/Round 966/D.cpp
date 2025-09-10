#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n;
  vector<long long> v(n);
  for(auto &i : v) cin >> i;
  string s; cin >> s;

  for(int i = 1; i < n; i++) v[i] += v[i-1];

  long long ans = 0;
  int l = 0, r = n-1;
  while(1){
    while(l < n && s[l] != 'L') l++;
    while(r >= 0 && s[r] != 'R') r--;
    
    if(l > r) break;
    ans += v[r]-(l ? v[l-1] : 0);
    l++; r--;
  }

  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int t = 1;
  cin >> t;
  while(t--) solve();
}