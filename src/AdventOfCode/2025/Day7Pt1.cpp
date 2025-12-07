#include <bits/stdc++.h>
using namespace std;

int main() {
  string s; cin >> s;

  set<int> p;
  p.insert(s.find('S'));
  
  int ans = 0;
  while(cin >> s) {
    set<int> nxt;
    for(auto i : p) {
      if(s[i] == '^') {
        ans++;
        nxt.insert(i-1);
        nxt.insert(i+1);
      } else nxt.insert(i);
    }
    swap(p, nxt);
  }

  cout << ans;
}