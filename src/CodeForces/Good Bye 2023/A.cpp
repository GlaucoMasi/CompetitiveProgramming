#include <bits/stdc++.h>
using namespace std;

int main() {
  int t; cin >> t;
  while(t--){
    int n, k; cin >> n >> k;
    vector<int> v(n); for(auto &i : v) cin >> i;
    
    long long prod = 1;
    for(auto &i : v) prod *= i;

    if(prod > 2023 || 2023%prod) cout << "NO\n";
    else if(prod != 2023 && !k) cout << "NO\n";
    else{
      cout << "YES\n";
      cout << 2023/prod << " "; k--;
      while(k--) cout << 1 << " ";
      cout << '\n';
    }
  }
}