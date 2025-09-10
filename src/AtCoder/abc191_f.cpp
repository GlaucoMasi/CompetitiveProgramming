#include <bits/stdc++.h>
using namespace std;

int main() {
  int n; cin >> n;
  vector<int> v(n); for(auto &i : v) cin >> i;

  int ans = 1;
  int t = *min_element(v.begin(), v.end());
  map<int, int> reach; reach[t] = t;
  
  auto add = [&](int i, int j){
    if(reach[i] == i || i >= t) return;

    if(reach.count(i)) reach[i] = __gcd(reach[i], j);
    else reach[i] = j;

    if(reach[i] == i) ans++;
  };

  for(auto i : v){
    for(long long j = 1; j*j <= i; j++){
      if(!(i%j)){
        add(j, i);
        add(i/j, i);
      }
    }
  }

  cout << ans;
}