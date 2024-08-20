#include <bits/stdc++.h>
using namespace std;

bool calc(int a1, int a2, int b1, int b2){
  int ra = 0, rb = 0;
  
  if(a1 > b1) ra++;
  else if(b1 > a1) rb++;

  if(a2 > b2) ra++;
  else if(b2 > a2) rb++;

  return ra > rb;
}

void solve() {
  int a1, a2, b1, b2;
  cin >> a1 >> a2 >> b1 >> b2;
  cout << calc(a1, a2, b1, b2) + calc(a2, a1, b1, b2) + calc(a1, a2, b2, b1) + calc(a2, a1, b2, b1) << '\n';
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int t = 1;
  cin >> t;
  while(t--) solve();
}