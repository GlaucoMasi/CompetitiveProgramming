#include <bits/stdc++.h>
using namespace std;

int main() {
  int mod = 1e9+7;
  int n, m; cin >> n >> m;
  vector<int> v(m+1);
  iota(v.begin(), v.end(), 0);

  for(int i = 1; i < n; i++){
    for(int j = m; j >= 0; j--) v[j] = v[j/2]%mod;
    for(int j = 1; j <= m; j++) v[j] = (v[j]+v[j-1])%mod;
  }

  cout << v[m];
}