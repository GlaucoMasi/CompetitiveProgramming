#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> g;
pair<int, int> f(int i, int p) {
  pair<int, int> ans;

  int best = 0;
  for(auto j : g[i]){
    if(j == p) continue;
    auto t = f(j, i);
    ans.first += t.second;
    best = max(best, t.first-t.second);
  }

  ans.second = ans.first+best;
  if(i) ans.first++;
  return ans;
}

int main() {
  cin >> n;
  g.resize(n);

  for(int i = 0; i < n-1; i++){
    int a, b; cin >> a >> b;
    g[--a].push_back(--b);
    g[b].push_back(a);
  }

  auto t = f(0, -1);
  cout << max(t.first, t.second);
}