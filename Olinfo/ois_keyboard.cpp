#include <bits/stdc++.h>
using namespace std;

void solve() {
  string s; cin >> s; s = '0'+s;
  if(s.size() == 1){
    cout << 0 << '\n';
    return;
  }

  vector<int> cum(s.size()); cum[0] = 0;
  for(int i = 1; i < s.size(); i++) cum[i] = cum[i-1] + abs(s[i]-s[i-1]);

  int ans = cum[s.size()-1];

  for(int i = 0; i < 10; i++){
    for(int j = i+1; j < 10; j++){
      if(i == j) continue;

      string t = s;
      for(int k = 1; k < t.size(); k++){
        if(t[k] == '0'+i) t[k] = '0'+j;
        else if(t[k] == '0'+j) t[k] = '0'+i;
      }

      vector<int> end(s.size()); end[s.size()-1] = 0;
      for(int i = s.size()-2; i >= 0; i--) end[i] = end[i+1] + abs(t[i]-t[i+1]);

      for(int k = 0; k < s.size()-1; k++) ans = min(ans, cum[k] + end[k+1] + abs((s[k]-'0') - (t[k+1]-'0'))); 
    }
  }

  cout << ans << '\n';
}

int main() {
  int t; cin >> t;
  while(t--) solve();
}