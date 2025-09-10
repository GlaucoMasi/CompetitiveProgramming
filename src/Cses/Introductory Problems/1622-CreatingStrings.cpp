#include <bits/stdc++.h>
using namespace std;

int main() {
  string s; cin >> s;
  vector<string> lista;

  sort(s.begin(), s.end());
  lista.push_back(s);
  while(next_permutation(s.begin(), s.end())) lista.push_back(s);

  cout << lista.size() << endl;
  for(auto i : lista) cout << i << endl;
}