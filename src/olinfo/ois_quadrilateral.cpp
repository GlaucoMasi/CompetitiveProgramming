#include <bits/stdc++.h>
using namespace std;

int main() {
  int n; cin >> n;
  vector<long long> v(n); for(auto &i : v) cin >> i;
  sort(v.begin(), v.end());

  for(int i = 3; i < n; i++){
    if(v[i-1]+v[i-2]+v[i-3] > v[i]){
      cout << v[i-3] << " " << v[i-2] << " " << v[i-1] << " " << v[i];
      return 0;
    }
  }

  cout << -1;
}