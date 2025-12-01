#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  int curr = 50, ans = 0;
  while(cin >> s) {
    int x = stoi(s.substr(1));
    if(s[0] == 'R') curr = (curr + x) % 100;
    else curr = (curr - x + 100) % 100;
    ans += curr == 0;
  }
  cout << ans << "\n";
}