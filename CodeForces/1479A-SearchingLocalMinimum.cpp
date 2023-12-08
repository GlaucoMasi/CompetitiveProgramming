#include <bits/stdc++.h>
using namespace std;

int main() {
  int n; cin >> n;
  vector<int> v(n+2, -1); v[0] = 1e6; v[n+1] = 1e6;

  int l = 0, r = n+1;
  while(l < r-1){
    int m = (l+r)/2;

    if(v[m] == -1){
      cout << "? " << m << endl;
      cin >> v[m];
    }

    if(v[m+1] == -1){
      cout << "? " << m+1 << endl;
      cin >> v[m+1];
    }

    if(v[m+1] < v[m]) l = m;
    else r = m;
  }

  cout << "! " << l+1 << endl;
}