#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
  int n; fin >> n;
  string s = "qwertyuiopasdfghjklzxcvbnm";
  map<char, char> m;

  for(int i = 0; i < s.size()-1; i++) m[s[i]] = s[i+1];

  string t; fin >> t;
  for(auto &c : t) c = m[c];
  fout << t;
}