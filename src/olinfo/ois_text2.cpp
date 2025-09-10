#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m; cin >> n >> m;

  vector<string> s(n); for(auto &i : s) cin >> i;
  vector<map<char, int>> v(m);
  for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) v[j][s[i][j]]++;

  pair<int, int> best = {1e9, 0};
  for(int i = 0; i < n; i++){
    int temp = 0;
    for(int j = 0; j < m; j++) temp += (n-v[j][s[i][j]]);
    best = min(best, {temp, i});
  }

  cout << best.second;
}