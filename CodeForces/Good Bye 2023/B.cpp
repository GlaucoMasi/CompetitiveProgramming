#include <bits/stdc++.h>
using namespace std;

int main() {
  int t; cin >> t;
  while(t--){
    long long l, r; cin >> l >> r;

    long long ans = l*r/__gcd(l, r);

    long long small = min(l, r); if(l == 1) small = r;
    long long sl = sqrt(l), sr = sqrt(r);
    for(long long i = 2; i <= sl; i++){
      if(!(l%i)){
        small = min(small, i);
        break;
      }

      if(!(r%i)){
        small = min(small, i);
        break;        
      }
    }

    if(ans == r) ans *= small;
    cout << ans << '\n';
  }
}