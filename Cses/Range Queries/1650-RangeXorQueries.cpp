#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, q; cin >> n >> q;
  vector<int> v(n+1); v[0] = 0;
  
  for(int i = 1; i <= n; i++){
    cin >> v[i];
    v[i] ^= v[i-1];
  }

  while(q--){
    int a, b; cin >> a >> b;
    cout << (v[b]^v[a-1]) << '\n';
  }
}