#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
  //ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  int n, k;
  cin >> n >> k;
  vector<long long> cum(n); cin >> cum[0];
  for(int i = 1; i < n; i++){
    cin >> cum[i];
    cum[i] += cum[i-1];
  }

  auto cost = [&](int l, int r){
    long long t = cum[r] - (l ? cum[l-1] : 0);
    return t*t;
  };

  vector<long long> dp(n), prev(n);
  for(int i = 0; i < n; i++) prev[i] = cum[i]*cum[i];
 
  for(int i = 0; i < k-1; i++){
    queue<array<int, 4>> q;
    q.push({0, n-1, 0, n-1});

    while(!q.empty()){
      auto [l, r, optl, optr] = q.front(); q.pop();
      if(l > r) continue;

      int m = (l+r)/2;
      pair<long long, int> best = {1e18, -1};
      for(int i = optl; i <= min(m, optr); i++) best = min(best, {(i ? prev[i-1] : 0)+cost(i, m), i});
      
      dp[m] = best.first;
      q.push({l, m-1, optl, best.second});
      q.push({m+1, r, best.second, optr});
    }

    prev = dp;
  }

  cout << prev[n-1];
}