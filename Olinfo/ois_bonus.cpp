#include <bits/stdc++.h>
using namespace std;

int main() {
  int n; cin >> n;
  int num = 0, den = 0;
  vector<pair<int, int>> v(n);
  for(auto &i : v){
    cin >> i.first >> i.second;
    num += i.first; den += i.second;
  }

  pair<double, int> ans; ans.first = 0;
  for(int i = 0; i < n; i++) ans = max(ans, {(double)(num-v[i].first)/(den-v[i].second), i});
  
  cout << ans.second;
}