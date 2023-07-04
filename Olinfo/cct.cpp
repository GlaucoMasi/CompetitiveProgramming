#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, k; cin >> n >> k;
  vector<int> t(n), car(n);
  for(auto &i : t) cin >> i;
  for(auto &i : car) cin >> i;
  
  vector<int> v(k+1, 2e9);
  v[0] = 0;

  for(int i = 0; i < n; i++){
    vector<int> next(k+1, 2e9);
    next[0] = v[k];

    for(int j = 0; j <= k; j++){
      if(v[j] == 2e9) continue;
      
      next[min(k, j+car[i])] = min(next[min(k, j+car[i])], v[j]+t[i]);
    }

    v = next;
  }

  int ans = 2e9;
  for(auto i : v) ans = min(ans, i);
  cout << ans;
}