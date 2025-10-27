#include <bits/stdc++.h>
using namespace std;

int fotosintesi(int n, string s) {
  int best = 0;
  map<array<int, 2>, int> m; m[{0, 0}] = -1;

  array<int, 2> curr = {0, 0};
  for(int i = 0; i < n; i++){
    if(s[i] > 'A') curr[s[i]-'B']++;
    else curr[0]--, curr[1]--;
    
    if(m.count(curr)) best = max(best, i-m[curr]);
    else m[curr] = i;
  }

  return best;
}

#ifndef EVAL
int main() {
  string S; cin >> S;
  cout << fotosintesi(S.size(), S) << endl;
}
#endif