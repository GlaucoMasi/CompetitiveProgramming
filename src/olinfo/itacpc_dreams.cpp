#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  auto pal = [&](int x) {
    string s = to_string(x);
    for(int i = 0; i < (s.size()+1)/2; i++) if(s[i] != s[s.size()-i-1]) return false;
    return true;
  };

  vector<int> ans(1e7+1);
  for(int i = 1; i <= 1e7; i++) ans[i] = (ans[i-1]+pal(i));

  int n; cin >> n;
  while(n--) {
    int a, b; cin >> a >> b;
    cout << ans[b]-ans[a-1] << '\n';
  }
}