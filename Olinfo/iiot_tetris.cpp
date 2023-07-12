#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  if((n*m)%4) cout << -1;
  else if(!(n%4)){
    cout << n*m/4 << '\n';
    for(int i = 0; i < n; i++){
      for(int j = 0; j < m; j++) cout << i/4*m+j << " ";
      cout << '\n';
    }
  }else if(!(m%4)){
    cout << n*m/4 << '\n';
    for(int i = 0; i < n; i++){
      for(int j = 0; j < m; j++) cout << i+j/4*n << " ";
      cout << '\n';
    }
  }else{
    cout << n*m/4 << '\n';
    for(int i = 0; i < n; i++){
      for(int j = 0; j < m; j++) cout << i/2*m/2+j/2 << " ";
      cout << '\n';
    }
  }
}