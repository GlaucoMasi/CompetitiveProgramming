#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

void solve() {
  int n; cin >> n;
  string s; cin >> s; s += '-';

  vector<int> need;
  int tot = 0, t = 0, last = -1;
  for(int i = 0; i <= n; i++){
    if(s[i] == '-'){
      if(last != i-1){
        tot++;
        need.push_back((i-last-1)/2);
      }

      last = i;
    }
  }

  sort(need.begin(), need.end(), greater<>());
  for(int i = 0; i < need.size(); i++) t = max(t, need[i]+i+1);
  
  cout << tot << " " << t << '\n';
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int t; cin >> t;
  while(t--) solve();
}