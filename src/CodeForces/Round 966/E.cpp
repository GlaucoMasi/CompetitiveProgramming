#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, m, k, w;
  cin >> n >> m >> k >> w;

  vector<long long> gor(w);
  for(auto &i : gor) cin >> i;
  sort(gor.begin(), gor.end(), greater<>());

  vector<long long> freq;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      long long h = min(k, min({j+1, m-j, m-k+1}));
      long long b = min(k, min({i+1, n-i, n-k+1}));
      freq.push_back(h*b);
    }
  }

  long long ans = 0;
  sort(freq.begin(), freq.end(), greater<>());
  for(int i = 0; i < w; i++) ans += freq[i]*gor[i];
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int t = 1;
  cin >> t;
  while(t--) solve();
}