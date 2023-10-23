#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<bitset<100>> v(n);

  for(int i = 0; i < n; i++) cin >> v[i];

  auto calc = [&] (int i, int j) { return (v[i]^v[j]).count(); };

  int ans = 0, next = 0;
  vector<bool> taken(n);
  vector<int> dist(n+1, 1e9);
  dist[0] = m; dist[n] = 1e9;
  while(next != n){
    taken[next] = 1;
    ans += dist[next];

    int j = next; next = n;
    for(int i = 0; i < n; i++){
      if(taken[i]) continue;

      dist[i] = min(dist[i], (int)calc(i, j));
      if(dist[i] < dist[next]) next = i;
    }
  }

  cout << ans;
}