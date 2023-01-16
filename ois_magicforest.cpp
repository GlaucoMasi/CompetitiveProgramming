#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m; cin >> n >> m;
  int mod = 1e9+7;
  
  vector<pair<int, pair<int, int>>> edges(m);
  for(auto &i : edges) cin >> i.second.first >> i.second.second >> i.first;
  sort(edges.begin(), edges.end(), greater<>());

  map<pair<int, int>, int> memo;
  for(auto i : edges){
    int a = i.second.first, b = i.second.second, c = i.first;
    a--; b--;

    memo[{a, c}] = (memo[{a, c}]+memo[{b, c+1}]+1)%mod;
    memo[{b, c}] = (memo[{b, c}]+memo[{a, c+1}]+1)%mod;
  }

  int ans = -m;
  for(auto i : memo) ans = (ans+i.second)%mod;
  cout << ans; 
}