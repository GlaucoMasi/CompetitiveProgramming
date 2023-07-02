#include <bits/stdc++.h>
using namespace std;

vector<array<int, 3>> v;

int bs(int a){
  int l = 0, r = v.size()+1;
  
  while(l < r-1){
    int m = (l+r)/2;

    if(m == 0 || v[m-1][0] > a) l = m;
    else if(v[m-1][0] < a) r = m;
    else return m;
  }

  return l;
}

int main() {
  int n; cin >> n;
  v.resize(n);

  for(auto &i : v) cin >> i[0] >> i[1] >> i[2];
  sort(v.begin(), v.end(), greater<>());

  vector<long long> dp(n+1); dp[0] = 0;
  for(int i = 1; i <= n; i++){
    auto [a, b, c] = v[i-1];
    int idx = bs(a+c);

    dp[i] = max(dp[i-1], dp[idx]+b);
  }

  cout << dp[n];
}