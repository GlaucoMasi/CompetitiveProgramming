#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;

  int a = 0, b = 0;
  int t;
  while(n--){
    cin >> t;

    if(t <= 11*k){
      a += t/k;
      b += t - t/k*k;
    }else{
      a += 10;
      b += t - 10*k;
    }
  }

  cout << a << " " << b;
}