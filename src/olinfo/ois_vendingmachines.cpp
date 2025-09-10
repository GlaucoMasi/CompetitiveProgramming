#include <bits/stdc++.h>
using namespace std;

void solve(){
  int n, q;
  cin >> n >> q;

  vector<int> v(n);
  for(auto &i : v) cin >> i;

  int cred = 0, a;
  bool hacked = 0;
  while(q--){
    cin >> a;

    if(a > 0) cred += a;
    else cred -= v[-a-1];

    if(cred < 0) hacked = 1;
  }

  cout << (hacked ? "HACKER" : "OK") << endl;
}

int main() {
  int t; cin >> t;
  while(t--) solve();
}