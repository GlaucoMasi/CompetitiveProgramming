#include <bits/stdc++.h>
using namespace std;

int main() {
  int n; cin >> n;
  int ans = n;
  vector<int> v(n);
  vector<bool> esc(n);
  
  for(int i = 0; i < n; i++){
    cin >> v[i];

    for(int j = 0; j < i; j++){
      if(v[j] < v[i] && !esc[j]){
        esc[j] = 1;
        ans--;
      }
    }
  }

  cout << ans;
}