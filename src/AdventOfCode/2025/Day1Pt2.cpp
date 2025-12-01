#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  int curr = 50, ans = 0;
  while(cin >> s) {
    int x = stoi(s.substr(1));
    if(s[0] == 'R') {
      if(x >= 100-curr) ans += (x + curr - 100) / 100 + 1;
      curr = (curr + x % 100) % 100;
    }else{
      if(x >= curr) ans += (x - curr) / 100 + (curr != 0);
      curr = (curr - x % 100 + 100) % 100;
    }
  }
  cout << ans << "\n";
}