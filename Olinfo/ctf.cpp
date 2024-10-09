#include <bits/stdc++.h>
using namespace std;

int main() {
  int q; cin >> q;
  while(q--){
    long long a, t = 1; cin >> a;
    while(t*2 <= a) t *= 2;
    cout << 2*(a-t)+1 << '\n';
  }
}