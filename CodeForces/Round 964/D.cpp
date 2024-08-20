#include <bits/stdc++.h>
using namespace std;

void solve() {
  string s, t; cin >> s >> t;

  int idx = 0;
  for(int i = 0; i < t.size(); i++){
    while(idx < s.size() && s[idx] != t[i] && s[idx] != '?') idx++;
    
    if(idx == s.size()){
      cout << "No\n";
      return;
    }

    s[idx] = t[i];
    idx++;
  }
  
  for(auto &i : s) if(i == '?') i = 'a';
  cout << "Yes\n" << s << '\n';
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int t = 1;
  cin >> t;
  while(t--) solve();
}