#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
  int n, q; fin >> n >> q;
  vector<int> v(n); for(auto &i : v) fin >> i;

  map<int, set<int>> m;
  for(int i = 0; i < n; i++) m[v[i]].insert(i);

  while(q--){
    int a, b; fin >> a >> b;
    auto t = m[b].upper_bound(a);
    
    int ans = 1e9;
    if(t != m[b].end()) ans = min(ans, *t-a);
    if(t != m[b].begin()) ans = min(ans, a-*prev(t));
    fout << ans << '\n';
  }
}