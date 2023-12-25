#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
  int n; fin >> n;

  set<string> s, ans;
  for(int i = 0; i < n; i++){
    string a, b, c; char t;
    fin >> a >> t >> b >> t >> c;
    if(!s.count(b) && !s.count(c) && !s.count(a)) ans.insert(a);
    s.insert(a);
  }

  fout << ans.size();
}