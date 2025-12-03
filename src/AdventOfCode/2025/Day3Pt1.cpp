#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  int ans = 0;
  while(cin >> s) {
    int best = 0, m = (s.back() - '0');
    for(int i = s.size()-2; i >= 0; i--) {
      int x = s[i] - '0';
      best = max(best, 10*x + m);
      m = max(m, x);
    }
    ans += best;
  }
  cout << ans;
}