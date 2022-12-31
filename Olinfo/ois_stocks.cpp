#include <bits/stdc++.h>
using namespace std;

int main() {
  int n; cin >> n;
  vector<int> v(n); for(auto &i : v) cin >> i;
  v.push_back(0);

  bool a;
  for(int i = 0; i < n; i++){
    cin >> a;
    v[i] *= a;
  }

  int sum = v[0], ans = 0;
  for(int i = 1; i <= n; i++){
    ans = max(ans, sum);
    
    if(v[i] == 0) sum = 0;
    else if(v[i] < v[i-1]) sum = v[i];
    else sum += v[i];
  }

  cout << ans;
}