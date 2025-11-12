#include <bits/stdc++.h>
using namespace std;

using bs2000 = bitset<2048>;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m, k; cin >> n >> m >> k;
  
  vector<bs2000> g(n);
  for(int i = 0; i < m; i++) {
    int a, b; cin >> a >> b;
    g[a-1][b-1] = 1;
    g[b-1][a-1] = 1;
  }

  for(int a = 0; a < n; a++) for(int b = a+1; b < n; b++) if((g[a] & g[b]).count() >= k) {
    cout << "YES";
    return 0;
  }

  cout << "NO";
}