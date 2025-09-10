#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, c; cin >> n >> c;
  vector<int> v(n); for(auto &i : v) cin >> i;

  vector<int> tot(c, 0); for(auto i : v) tot[i]++;

  bool t = 1;
  int l = 0, r = n-1;
  while(t) {
    t = 0;
    
    if(tot[v[l]] > 1){
      tot[v[l]]--;
      l++;

      t = 1;
    }

    if(tot[v[r]] > 1){
      tot[v[r]]--;
      r--;

      t = 1;
    }
  }

  cout << r-l+1;
}