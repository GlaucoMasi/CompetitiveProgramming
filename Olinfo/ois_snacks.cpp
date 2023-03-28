#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, x; cin >> n >> x;
  vector<int> v(n);
  for(auto &i : v) cin >> i;
  sort(v.begin(), v.end());

  int ans = 0;
  for(int i = 0; i < n; i++){
    if(i != n-1 && v[i]+v[i+1] <= x) i++;
    ans++;
  }

  cout << ans;
}