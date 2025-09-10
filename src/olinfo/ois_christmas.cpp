#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, b;
  cin >> n >> b;

  vector<bool> v(1e4+5);
  v[0] = 1;

  int under = -1, over = 1e9;
  int a;
  for(int i = 0; i < n; i++){
    cin >> a;

    for(int j = 1e4; j >= a; j--){
      if(v[j-a]){
        v[j] = 1;
      
        if(j >= b) over = min(over, j);
        else under = max(under, j);
      }
    }
  }

  if(over == 1e9) cout << under;
  else cout << over;
}