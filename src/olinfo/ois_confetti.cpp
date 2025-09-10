#include <bits/stdc++.h>
using namespace std;

int main() {
  int n; cin >> n;
  long long gcd; cin >> gcd;

  for(int i = 1; i < n; i++){
    long long a; cin >> a;
    gcd = __gcd(gcd, a);
  }

  int rad = sqrt(gcd)+3;
  set<long long> ans;
  for(int i = 1; i <= rad; i++){
    if(!(gcd%i)){
      ans.insert(i);
      ans.insert(gcd/i);
    }
  }

  for(auto i : ans) cout << i << " ";
}