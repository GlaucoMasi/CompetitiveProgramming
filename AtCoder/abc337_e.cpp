#include <bits/stdc++.h>
using namespace std;

int main() {
  int n; cin >> n; n--;
  int m = log2(n)+1;
  cout << m << endl;

  vector<vector<int>> v(m);
  for(int i = 1; i <= n; i++){
    for(int j = 0; j < m; j++) if(i&(1<<j)) v[j].push_back(i);
  }

  for(auto i : v){
    cout << i.size() << " ";
    for(auto j : i) cout << j << " ";
    cout << endl;
  }

  int ans = 0;
  string t; cin >> t;
  for(int i = 0; i < m; i++) if(t[i] == '1') ans += (1<<i);
  
  if(ans != 0) cout << ans << endl;
  else cout << n+1;
}