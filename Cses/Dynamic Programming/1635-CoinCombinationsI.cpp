#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");

int main() {
  int mod = 1e9 + 7;
  int n, x; cin >> x >> n;
  
  vector<int> v(n+1, 0), c(x);
  for(auto &i : c) cin >> i;
  v[0] = 1;
  for(int i = 1; i <= n; i++){
    for(auto j : c){
      if(j > i) continue;

      v[i] = (v[i] + v[i-j]) % mod;
    }
  }

  cout << v[n];
}