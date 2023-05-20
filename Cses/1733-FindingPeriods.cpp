#include <bits/stdc++.h>
using namespace std;

int main() {
  string a; cin >> a;
  vector<int> v(a.size());

  int l = 1, i = 1, r = 0;
  while(i < a.size()){
    if(i > r){
      l = i, r = i-1;
      while(r+1 < a.size() && a[r+1] == a[r-l+1]) r++;
      v[i] = r-l+1;
    }else{
      if(v[i-l] < r-i+1) v[i] = v[i-l];
      else{
        l = i;
        while(r+1 < a.size() && a[r+1] == a[r-l+1]) r++;
        v[i] = r-l+1;
      }
    }

    if(v[i] == a.size()-i) cout << i << " ";
    i++;
  }

  cout << a.size();
}