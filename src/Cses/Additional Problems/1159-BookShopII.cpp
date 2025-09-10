#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  int n, x; cin >> n >> x;
  vector<int> dp(x+1);

  vector<int> h(n), s(n), k(n);
  for(auto &i : h) cin >> i;
  for(auto &i : s) cin >> i;
  for(auto &i : k) cin >> i;

  vector<array<int, 2>> opts;
  for(int i = 0; i < n; i++){
    int t = 1;
    
    while(t <= k[i]){
      opts.push_back({s[i]*t, h[i]*t});
      k[i] -= t; t *= 2;
    }

    if(k[i]) opts.push_back({s[i]*k[i], h[i]*k[i]});
  }

  for(auto [pages, price] : opts) for(int i = x; i >= price; i--) dp[i] = max(dp[i], dp[i-price]+pages);
  cout << dp[x];
}