#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, q; cin >> n >> q;
  vector<int> v(n); for(auto &i : v) cin >> i;

  int dist = 0;
  vector<int> ans(n);
  map<int, bool> m;
  for(int i = n-1; i >= 0; i--){
    if(!m.count(v[i])){
      dist++;
      m[v[i]] = 1;
    }

    ans[i] = dist;
  }
  
  int a;
  while(q--){
    cin >> a;
    cout << ans[a-1] << endl;
  }
}