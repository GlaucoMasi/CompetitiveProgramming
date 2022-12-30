#include <bits/stdc++.h>
using namespace std;

int main() {
  int n; cin >> n;
  vector<pair<int, int>> v(n);

  for(int i = 0; i < n; i++) cin >> v[i].first >> v[i].second;
  
  sort(v.begin(), v.end());

  int tot = 0;
  map<int, int> m;
  for(auto [a, b] : v){
    if(m[a]) m[a]--;
    else tot++;
    
    m[b]++;
  }

  cout << tot;
}