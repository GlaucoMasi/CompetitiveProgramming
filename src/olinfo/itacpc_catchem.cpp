#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  set<string> names;
  
  for(int i = 0; i < n; i++) {
    string name; cin >> name;
    names.insert(name);
  }

  cout << names.size()+1;
}