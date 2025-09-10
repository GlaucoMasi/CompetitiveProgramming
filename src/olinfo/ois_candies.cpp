#include <bits/stdc++.h>
using namespace std;

int main() {
  int n; cin >> n;
  vector<int> v(n);
  for(auto &i : v) cin >> i;

  sort(v.begin(), v.end());
  long long tot = 1, curr = 1;
  for(int i = 1; i < n; i++){
    curr += (v[i] != v[i-1]);
    tot += curr;
  }

  cout << tot;
}