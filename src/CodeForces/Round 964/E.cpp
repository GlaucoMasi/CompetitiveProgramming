#include <bits/stdc++.h>
using namespace std;

vector<int> memo(2e5+1);

void solve() {
  int l, r; cin >> l >> r;
  cout << memo[r]+memo[l]-2*memo[l-1] << '\n';
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  
  for(int i = 1; i <= 2e5; i++) memo[i] = memo[i/3]+1;
  for(int i = 1; i <= 2e5; i++) memo[i] += memo[i-1];
  
  int t = 1;
  cin >> t;
  while(t--) solve();
}