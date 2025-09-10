#include <bits/stdc++.h>
using namespace std;

string conv(int t){
  string a = "";
  
  while(t > 0){
    a += (char)('0'+t%10);
    t /= 10;
  }

  reverse(a.begin(), a.end());
  return a;
}

int main() {
  string a; cin >> a;
  int n; cin >> n;

  map<string, int> s; s[a] = 0;
  for(int i = 1; i <= n; i++) s[a + conv(i)] = i;

  for(int i = 0; i < n; i++){
    string t; cin >> t;
    s[t] = 1e8;
  }

  pair<int, string> ans = {1e8, ""};
  for(auto i : s) ans = min(ans, {i.second, i.first});
  cout << ans.second;
}