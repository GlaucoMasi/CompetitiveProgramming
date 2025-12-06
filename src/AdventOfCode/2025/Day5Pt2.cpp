#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  
  vector<pair<long long, int>> edg;
  while(getline(cin, s) && !s.empty()) {
    int idx = s.find('-');
    long long l = stoll(s.substr(0, idx)), r = stoll(s.substr(idx+1));
    edg.push_back({l, -1});
    edg.push_back({r, 1});
  }
  sort(edg.begin(), edg.end());

  int open = 0;
  long long ans = 0, last = 0;
  for(auto [a, b] : edg) {
    open -= b;
    if(b == -1 && open == 1) last = a;
    else if(b == 1 && open == 0) ans += a - last + 1;
  }

  cout << ans;
}