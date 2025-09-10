#include <bits/stdc++.h>
using namespace std;

void solve(){
  int k; cin >> k;
  int ans = 0;

  int found = 0;
  vector<bool> v(10);

  int add = k;
  while(found != 10){
    int temp = add;

    while(temp > 0){
      if(!v[temp%10]){
        v[temp%10] = 1;
        found++;
      }

      temp /= 10;
    }

    add += k;
    ans++;
  }

  cout << ans << endl;
}

int main() {
  int n; cin >> n;
  while(n--) solve();
}