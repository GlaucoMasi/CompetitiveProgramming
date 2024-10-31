#include <bits/stdc++.h>
using namespace std;

int main() {
  int n; cin >> n;
  vector<pair<bool, int>> v(n);

  for(int i = 0; i < n; i++) v[i] = {0, i};

  for(int i = 0; i < n-1; i++){
    int a; cin >> a; a--;
    v[a].first = 1; v[a].second = a;
  }

  sort(v.begin(), v.end());

  cout << v[0].second+1;
}