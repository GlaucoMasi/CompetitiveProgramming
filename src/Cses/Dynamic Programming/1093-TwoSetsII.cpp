#include <bits/stdc++.h>
using namespace std;

int main() {
  int mod = 1e9+7;
  int n; cin >> n;
  int sum = (n+1)*n/2;

  if(sum % 2){
    cout << 0;
    exit(0);
  }

  sum /= 2;
  vector<long long> ans(sum+1, 0);
  ans[1] = 1;

  for(int i = 2; i <= n; i++){
    for(int j = sum; j > i; j--){
      ans[j] = (ans[j] + ans[j-i]) % mod;
    }
  }

  cout << ans[sum];
}