#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  string s; cin >> s;

  int l = 0, r = 0;
  vector<int> z(s.size());
  for(int i = 1; i < s.size(); i++){
    if(i < r) z[i] = min(r-i, z[i-l]);
    while(i+z[i] < s.size() && s[z[i]] == s[i+z[i]]) z[i]++;
    if(i+z[i] > r){
      l = i;
      r = i+z[i];
    }
  }

  vector<int> kmp(s.size());
  for(int i = 1; i < s.size(); i++){
    kmp[i] = kmp[i-1];
    while(kmp[i] > 0 && s[i] != s[kmp[i]]) kmp[i] = kmp[kmp[i]-1];
    if(s[i] == s[kmp[i]]) kmp[i]++;
  }

  for(auto i : z) cout << i << " "; cout << '\n';
  for(auto i : kmp) cout << i << " ";
}