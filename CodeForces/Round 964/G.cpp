#include <bits/stdc++.h>
using namespace std;

void solve() {
  int l = 1, r = 999;
  while(l < r-1){
    int m1 = l + (r-l)/3, m2 = l + (r-l)/3*2;

    cout << "? " << m1 << " " << m2 << '\n';
    cout.flush();
    int ans; cin >> ans;

    if(ans == m1*m2) l = m2+1;
    else if(ans == m1*(m2+1)) l = m1+1, r = m2+1;
    else r = m1+1;
  }
  cout << "! " << l << '\n';
  cout.flush();
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int t = 1;
  cin >> t;
  while(t--) solve();
}