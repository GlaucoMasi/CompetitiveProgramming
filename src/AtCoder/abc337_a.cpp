#include <bits/stdc++.h>
using namespace std;

int main() {
  int n; cin >> n;
  int a = 0, b = 0;
    
  int t;
  for(int i = 0; i < n; i++){
    cin >> t; a += t;
    cin >> t; b += t;
  }

  if(a > b) cout << "Takahashi";
  else if(a < b) cout << "Aoki";
  else cout << "Draw";
}