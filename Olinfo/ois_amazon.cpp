#include <bits/stdc++.h>
using namespace std;

int n;
set<long long> vis;
map<long long, vector<long long>> g, prec;

void f(long long i){
  vis.insert(i);
  prec[i] = vector<long long>(n+1, -1);
  prec[i][0] = i;
  int self = 0;
  for(auto j : g[i]){
    if(!vis.count(j)) f(j);

    if(i == j){
      self++;
      continue;
    }

    for(int k = 1; k <= n; k++) prec[i][k] = max(prec[i][k], prec[j][k-1]);
  }

  while(self--) for(int k = n; k >= 1; k--) prec[i][k] = max(prec[i][k], prec[i][k-1]);
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  cin >> n;
  for(int i = 0; i < n; i++){
    long long l, r; cin >> l >> r;
    g[l].push_back(r);
  }

  for(auto i : g) if(!vis.count(i.first)) f(i.first);

  int q; cin >> q;
  while(q--){
    long long x, u, v; cin >> x >> u >> v;

    long long ans = (u ? -1 : x);
    if(prec.count(x)) for(int i = u; i <= v; i++) ans = max(ans, prec[x][i]);
    cout << ans << " ";
  }
}