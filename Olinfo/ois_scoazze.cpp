#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k; cin >> n >> k;
  vector<int> c(n), v(n);
  for(auto &i : c) cin >> i;

  long long ans = 0;
  for(int i = 0; i < k; i++){
    int t, q; cin >> t >> q;
    if(v[t] + q > c[t]){
      ans += c[t]-v[t];
      v[t] = q;
    }else v[t] += q;
  }

  for(int i = 0; i < n; i++) if(v[i]) ans += c[i]-v[i];
  cout << ans;
}