#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, q; cin >> n >> q;
  map<int, vector<int>> m;

  for(int i = 1; i <= n; i++){
    int a; cin >> a;
    m[a].push_back(i);
  }

  while(q--){
    int x, k; cin >> x >> k;

    if(!m.count(x) || m[x].size() < k) cout << -1 << '\n';
    else cout << m[x][k-1] << '\n';
  }
}