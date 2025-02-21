#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  int n, m; cin >> n >> m;
  vector<int> v(n);

  while(m--){
    int a, b, w; cin >> a >> b >> w;
    v[a] -= w;
    v[b] += w;
  }

  vector<array<int, 3>> ans;
  for(int i = 1; i < n; i++){
    if(v[i] > 0) ans.push_back({i, 0, v[i]});
    else if(v[i] < 0) ans.push_back({0, i, -v[i]});
  }

  cout << ans.size() << '\n';
  for(auto [a, b, c] : ans) cout << a << " " << b << " " << c << '\n';
}