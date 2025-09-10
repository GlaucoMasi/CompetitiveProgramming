#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k; cin >> n >> k;
  vector<int> v(n);
  for(auto &i : v) cin >> i;
  sort(v.begin(), v.end(), greater<>());

  long long tot = 0, aim = (long long)k*n;
  for(auto &i : v) tot += i;

  if(aim == tot) cout << 0;
  else if(aim > tot) cout << 1;
  else{
    for(int i = 0; i < n; i++){
      tot -= v[i]-1;
      if(tot <= aim){
        cout << i+1;
        break;
      }
    }
  }
}