#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m; cin >> n >> m;
  string a; cin >> a;
  
  int p = 31, mod = 1e9+7;

  unordered_map<int, int> av;
  for(int j = 0; j < m; j++){
    int temp = 0;
    string b; cin >> b;
    
    for(auto i : b){
      temp = (temp+i)%mod;
      temp = (temp*p)%mod;
    }

    av[temp]++;
  }

  vector<int> dp(n+1); dp[0] = 1;
  for(int i = 1; i <= n; i++){
    int temp = 0;

    for(int j = i-1; j < n; j++){
      temp = (temp+a[j])%mod;
      temp = (temp*p)%mod;

      dp[j+1] = (dp[j+1] + ((av.count(temp) ? av[temp] : 0) * dp[i-1])%mod)%mod;
    }
  }

  cout << dp[n];
}