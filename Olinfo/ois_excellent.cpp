#include <bits/stdc++.h>
using namespace std;

int main() {
  int n; cin >> n;
  
  for(int i = 0; i <= n; i++){
    if(!((i + 5*(n-i))%3)){
      for(int k = 0; k < i; k++) cout << 1;
      for(int k = i; k < n; k++) cout << 5;
      return 0;
    }
  }

  cout << -1;
}