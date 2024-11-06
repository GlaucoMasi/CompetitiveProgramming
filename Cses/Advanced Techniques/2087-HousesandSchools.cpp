#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  int n, k; cin >> n >> k;
  vector<long long> v(n), cum(n+1);
  for(auto &i : v) cin >> i;
  for(int i = 1; i <= n; i++) cum[i] = cum[i-1]+v[i-1];

  vector<long long> toleft(n+1), toright(n+1);
  for(int i = n-1; i > 0; i--) toleft[i] = toleft[i+1]+cum[n]-cum[i];
  for(int i = 2; i <= n; i++) toright[i] = toright[i-1]+cum[i-1];

  auto right = [&](long long l, long long r){
    if(l >= r) return 0LL;
    return toright[r]-toright[l]-(r-l)*(cum[l-1]);
  };

  auto left = [&](long long l, long long r){
    if(l >= r) return 0LL;
    return toleft[l]-toleft[r]-(r-l)*(cum[n]-cum[r]);
  };

  auto calc = [&](int l, int r){
    int m = (l+r)/2;
    long long ans = 0;
    ans += left(l, m);
    ans += right(m+1, r);
    return ans;
  };

  vector<long long> dp(n+1), prev = toright;
  for(int i = 1; i < k; i++){
    queue<array<int, 4>> q;
    q.push({1, n, 1, n});
    
    while(!q.empty()){
      auto [l, r, optl, optr] = q.front(); q.pop();
      if(l > r) continue;

      int m = (l+r)/2;

      pair<long long, int> best = {2e18, -1};
      for(int i = optl; i <= min(m, optr); i++) best = min(best, {prev[i] + calc(i, m), i});
      dp[m] = best.first;

      q.push({l, m-1, optl, best.second});
      q.push({m+1, r, best.second, optr});
    }

    prev = dp;
  }

  long long best = 2e18;
  for(int i = 1; i <= n; i++) best = min(best, prev[i] + toleft[i]);
  cout << best;
}