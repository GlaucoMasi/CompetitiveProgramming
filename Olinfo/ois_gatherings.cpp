#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, x; cin >> n >> x;
  vector<int> v(n); for(auto &i : v) cin >> i;
  
  long long sum = 0;
  for(int i = 0; i < n; i++) sum += (lower_bound(v.begin()+i+1, v.end(), v[i]+x)-v.begin()-i-1);

  cout << sum;
}