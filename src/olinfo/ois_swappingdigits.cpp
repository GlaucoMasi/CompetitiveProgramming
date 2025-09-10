#include <bits/stdc++.h>
using namespace std;

int solve() {
  string a; cin >> a;
  if(a.size() < 2) return -1;

  string end = a.substr(a.size()-2, 2);
  if(end == "00" || end == "25" || end == "50" || end == "75") return 0;
  if(end == "52" || end == "05" || end == "57") return 1;

  vector<int> v(10);
  for(int i = 0; i < a.size()-2; i++) v[a[i]-'0']++;

  if(a[a.size()-2] == '0' && v[0]) return 1;
  if(a[a.size()-2] == '5' && v[0]) return 1;
  if(a[a.size()-2] == '2' && v[5]) return 1;
  if(a[a.size()-2] == '7' && v[5]) return 1;

  if(a[a.size()-1] == '0' && (v[5] || v[0])) return 1;
  if(a[a.size()-1] == '5' && (v[2] || v[7])) return 1;

  for(int i = a.size()-2; i < a.size(); i++) v[a[i]-'0']++;
  if(v[0] > 1 || (v[2] && v[5]) || (v[7] && v[5]) || (v[5] && v[0])) return 2;

  return -1;
}

int main() {
  int t; cin >> t;
  while(t--) cout << solve() << '\n';
}