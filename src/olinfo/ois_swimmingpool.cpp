#include <bits/stdc++.h>
using namespace std;

int main() {
  int n; cin >> n;
  vector<int> v(n);
  for(auto &i : v) cin >> i;

  int best = 1e9;
  for(int i = 0; i < n; i++) best = min(best, max(v[i]-v[0], v[n-1]-v[i]));
  cout << best;
}