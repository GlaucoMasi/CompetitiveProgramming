#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
  int n, x; cin >> n >> x;
  map<int, int> m;

  pair<int, int> ans = {-1, -1};
  for(int i = 0; i < n; i++){
    int a; cin >> a;
    if(m.count(x-a)) ans = {i+1, m[x-a]};
    m[a] = i+1;
  }

  if(ans.first == -1) cout << "IMPOSSIBLE";
  else cout << ans.first << " " << ans.second;
}