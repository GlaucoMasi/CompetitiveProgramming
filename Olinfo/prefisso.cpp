#include <bits/stdc++.h>
using namespace std;

int main() {
  int n; cin >> n;
  vector<string> v(n);
  for(auto &i : v) cin >> i;

  int i = 0; bool ok = 1;
  for(i; i < v[0].size() && ok; i++){
    ok = 1;
    for(int j = 1; j < n; j++) if(v[j-1][i] != v[j][i]) ok = 0;
  }

  cout << i-(!ok);
}