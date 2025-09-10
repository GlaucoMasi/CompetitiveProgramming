#include <bits/stdc++.h>
using namespace std;

int main() {
  int t, mod = 1e9 + 7;
  cin >> t;

  vector<vector<long long>> ans(1e6+1, vector<long long>(2, 0));
  ans[1][0] = ans[1][1] = 1;

  for(int i = 2; i <= 1e6; i++){
    ans[i][0] = (ans[i-1][1] + (2*ans[i-1][0])%mod)%mod;
    ans[i][1] = (ans[i-1][0] + (4*ans[i-1][1])%mod)%mod;
  }

  int n;
  while(t--){
    cin >> n;
    cout << (ans[n][0] + ans[n][1]) % mod << endl;
  }
}