#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
  ll n, k, m, p, q;
  cin >> n >> k >> m >> p >> q;
  
  vector<ll> dp(n+1);
  dp[0] = q-p;

  deque<ll> disp, pari;
  disp.push_back(0);

  for(int i = 1; i <= n; i++){
    while(!disp.empty() && disp.front() < i-k) disp.pop_front();
    while(!pari.empty() && pari.front() < i-k) pari.pop_front();

    ll ans = 1e18;
    if(!disp.empty()) ans = min(ans, dp[disp.front()]+m);
    if(!pari.empty()) ans = min(ans, dp[pari.front()]);
    dp[i] = -ans;

    while(!pari.empty() && dp[pari.back()] > dp[i]) pari.pop_back();
    pari.push_back(i);

    swap(disp, pari);
  }

  cout << dp[n];
}