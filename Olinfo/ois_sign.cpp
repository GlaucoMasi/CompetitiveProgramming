#include <bits/stdc++.h>
using namespace std;

int main() {
  int t; cin >> t;

  while(t--){
    long long a, b; cin >> a >> b;

    if(a <= 0 && b >= 0) cout << '0';
    else if(a > 0) cout << '+';
    else if((b-a)%2) cout << '+';
    else cout << '-';
    
    cout << endl;
  }
}
