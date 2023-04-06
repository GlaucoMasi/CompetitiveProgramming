#include <bits/stdc++.h>
using namespace std;

int main() {
  int n; cin >> n;

  vector<int> v(n);
  for(auto &i : v) cin >> i;

  long long tot = 0; int cost = 1e5;
  for(int i = 0; i < n; i++){
    int a; cin >> a;

    cost = min(cost, v[i]);
    tot += a*cost;
  }

  cout << tot;
}