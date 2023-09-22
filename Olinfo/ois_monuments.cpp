#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, t; long long k;
  cin >> n >> k >> t;

  if(n == 0){
    cout << 0;
    return 0;
  }

  vector<long long> v(n);
  for(auto &i : v){
    cin >> i;
    if(i >= k) i -= k;
  }
  sort(v.begin(), v.end());

  for(int i = 0; i < n; i++) v.push_back(v[i]+k);

  int ans = 1e9;
  for(int i = 0; i < n-1; i++) if(v[i+1] - v[i] > t) ans = 0;

  int l = -1, r = 0; long long left;
  while(l+1 < n && ans){
    l++;
    while(l && v[l-1] == v[l]) l++;

    if(l) left = v[l]-v[l-1]-1;
    else left = v[l] + 2*k - v.back() - 1;

    r = max(r, l);
    while(v[r+1]-v[l]+1 + left <= t) r++;
  
    ans = min(ans, r-l+1);
  }

  cout << ans;
}