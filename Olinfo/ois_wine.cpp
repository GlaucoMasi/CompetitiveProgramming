#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  int n; cin >> n;
  long long k; cin >> k;
  vector<long long> v(n);
  for(auto &i : v) cin >> i;
  for(int i = 1; i < n; i++) v[i] += v[i-1];

  long long l = 0, r = 2e14+1;
  while(l < r-1){
    long long m = (l+r)/2;

    long long tot = 0;
    for(int i = 0; i < n; i++) tot += (upper_bound(v.begin(), v.end(), (i ? v[i-1] : 0)+m)-v.begin()-i);

    if(tot < k) l = m;
    else r = m;
  }

  for(int i = 0; i < n; i++) k -= (lower_bound(v.begin(), v.end(), (i ? v[i-1] : 0)+r)-v.begin()-i);
  for(int i = 0; i < n && k; i++){
    int idx = lower_bound(v.begin(), v.end(), (i ? v[i-1] : 0)+r)-v.begin();
    if(v[idx] != (i ? v[i-1] : 0)+r) continue;
    if(!(--k)) cout << i << " " << idx << '\n';
  }
}