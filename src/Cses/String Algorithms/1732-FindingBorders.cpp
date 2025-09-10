#include <bits/stdc++.h>
using namespace std;

int main() {
  string s; cin >> s;
  vector<int> z(s.size());

  int l = 1, r = 1;
  for(int i = 1; i < s.size(); i++){
    if(i < r) z[i] = min(z[i-l], r-i);
    while(i+z[i] < s.size() && s[i+z[i]] == s[z[i]]) z[i]++;
    if(i+z[i] > r){
      l = i;
      r = i+z[i];
    }
  }

  for(int i = s.size()-1; i >= 1; i--) if(i+z[i] == s.size()) cout << z[i] << " ";
}