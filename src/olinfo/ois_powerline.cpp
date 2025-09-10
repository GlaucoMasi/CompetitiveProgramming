#include <bits/stdc++.h>
using namespace std;

int main() {
  int n; cin >> n;
  vector<int> v(n); for(auto &i : v) cin >> i;
  vector<int> needed(n);

  for(int i = n-2; i >= 0; i--){
    if(v[i] < v[i+1]){
      needed[i] = needed[i+1]+1;
      v[i] = v[i+1];
    }
  }

  cout << *max_element(needed.begin(), needed.end());
}