#include <bits/stdc++.h>
using namespace std;

int main() {
  int n; cin >> n;
  vector<bitset<3000>> v(n);
  for(int i = 0; i < n; i++) for(int j = 0; j < n; j++){
    char c; cin >> c;
    if(c == '1') v[i].set(j, 1);
  }

  long long ans = 0;
  for(int i = 0; i < n; i++){
    for(int j = i+1; j < n; j++){
      if(!v[i][j]) continue;

      bitset<3000> b = v[i] & v[j];
      b = b >> j;
      ans += b.count();
    }
  }

  cout << ans;
}