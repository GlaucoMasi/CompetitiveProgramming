#include <bits/stdc++.h>
using namespace std;

int main() {
  int n; cin >> n;
  
  int a, last, ans; 
  cin >> last; ans = last;
  for(int i = 1; i < n; i++){
    cin >> a;
    ans = max(ans, a-last);
    last = a;
  }
  
  cout << ans;
}