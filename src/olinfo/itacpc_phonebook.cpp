#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int ans = 0;
  int n; cin >> n;
  for(int i = 0; i < n; i++) {
    string num; cin >> num;
    ans += (num.substr(0, 3) == "+39" && num.size()-3 >= 9 && num.size()-3 <= 10);
  }

  cout << ans;
}