#include <bits/stdc++.h>
using namespace std;

bool solve(){
  string s; cin >> s;
  int i = 0;

  while(s[i] == 'A' && i < s.size()) i++;
  while(s[i] == 'B' && i < s.size()) i++;
  while(s[i] == 'C' && i < s.size()) i++;

  return (i == s.size());
}

int main() {
  if(solve()) cout << "Yes";
  else cout << "No";  
}