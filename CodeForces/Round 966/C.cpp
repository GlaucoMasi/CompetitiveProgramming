#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n;
  vector<int> v(n);
  for(auto &i : v) cin >> i;

  int m; cin >> m;
  while(m--){
    map<int, char> car;
    string s; cin >> s;

    bool ok = (s.size() == n);

    vector<bool> used(26);
    for(int i = 0; i < n && ok; i++){
      if(!car.count(v[i])){
        if(used[s[i]-'a']) ok = 0;
        else{
          used[s[i]-'a'] = 1;
          car[v[i]] = s[i];
        }
      }else if(car[v[i]] != s[i]) ok = 0;
    }

    cout << (ok ? "YES\n" : "NO\n");
  }
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int t = 1;
  cin >> t;
  while(t--) solve();
}