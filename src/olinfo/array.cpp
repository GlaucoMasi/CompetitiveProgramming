#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  int a = 0;
  for(int i = 0; i < n; i++){
    int m;
    cin >> m;

    a = a + m;
  }

  float b = a; 
  b = b/n;
  
  cout << a << " " << b;
}