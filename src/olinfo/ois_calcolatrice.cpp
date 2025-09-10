#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  string s, rev = ""; fin >> s;

  vector<int> v = {0, 1, 2, -1, -1, 5, 9, -1, 8, 6};
  auto revc = [&](char c){
    return (char)('0'+v[c-'0']);
  };

  bool invalid = 0;
  for(auto i : s){
    char c = revc(i);
    if(c == '0'-1) invalid = 1;
    rev.push_back(c);
  }
  
  reverse(rev.begin(), rev.end());
  if(invalid || rev[0] == '0') fout << s;
  else fout << min(stoi(s), stoi(rev));
}