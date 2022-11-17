#include <bits/stdc++.h>
using namespace std;

void solve(){
  int n, r, t;
  cin >> n >> r >> t;

  int a;
  double sum = 0;
  for(int i = 0; i < n; i++){
    cin >> a;
    sum += a;
  }

  sum /= n;
  cout << (sum > r+t ? "Cheater" : "Innocent") << endl;
}

int main() {
  int k; cin >> k;
  while(k--) solve();
}