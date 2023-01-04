#include <bits/stdc++.h>
using namespace std;

int main() {
  int n; cin >> n;
  vector<int> v(n), ans(n);
  for(auto &i : v) cin >> i;

  for(int i = 0; i < n; i++){
    ans[i] = 1;
    
    for(int j = 0; j < i; j++){
      if(v[i] < v[j] || !(v[i]%v[j])) ans[i] = max(ans[i], ans[j]+1);
    }
  }

  cout << n-*max_element(ans.begin(), ans.end());
}