#include <bits/stdc++.h>
using namespace std;

void solve() {
  long long n;
  cin >> n;

  for(int i = 2; i < 60 && n > 6; i++){
    int l = 2, r = 1e9;
    while(l < r){
      int m = l + (r-l)/2;

      long long temp = 1;
      
      for(int j = 0; j < i; j++){
        if(temp > n) break;
        if(2000000000000000000/m < temp){
          temp = n+1;
          break;
        }

        temp *= m;
        temp++;
      }

      if(temp == n){
        cout << "YES" << '\n';
        return;
      }else if(temp > n) r = m;
      else l = m+1;
    }
  }

  cout << "NO" << '\n';
}

int main() {
  int t; cin >> t;
  while(t--) solve();
}