#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, mod = 1e9+7;
  cin >> n;

  vector<long long> v(n+1);
  v[0] = 1;
  for(int i = 0; i <= n; i++){
    for(int j = 1; j <= 6; j++){
      if(i-j < 0) continue;

      v[i] = (v[i] + v[i-j]) % mod;
    }
  }

  cout << v[n];
}