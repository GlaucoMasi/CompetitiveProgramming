#include <bits/stdc++.h>
using namespace std;

int main() {
  string a, b; cin >> a >> b;
  b = b+'$'+a;

  vector<int> v(b.size(), 0); v[0] = b.size();
  int ans = 0;

  int i = 1, l = 1, r = 0;
  while(i < v.size()){
    if(i > r){
      l = i; r = i-1;
      while(r+1 < b.size() && b[r+1] == b[r-l+1]) r++;
      v[i] = (r-l+1);
    }else{
      if(v[i-l] < r-i+1) v[i] = v[i-l];
      else{
        l = i;
        while(r+1 < b.size() && b[r+1] == b[r-l+1]) r++;
        v[i] = (r-l+1);
      }
    }

    if(v[i] == b.size()-a.size()-1) ans++;
    i++;
  }

  cout << ans;
}