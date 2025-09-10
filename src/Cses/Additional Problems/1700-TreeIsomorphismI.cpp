#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int idx = 0;
map<vector<int>, int> m;

int f(int i, int p, vector<vector<int>> &g){
  vector<int> curr;
  for(auto j : g[i]){
    if(j == p) continue;
    curr.push_back(f(j, i, g));
  }

  sort(curr.begin(), curr.end());
  if(!m.count(curr)) m[curr] = idx++;

  return m[curr];
}

void solve() {
  int n; cin >> n;
  vector<vector<int>> g(n), h(n);

  idx = 0;
  m.clear();

  for(int i = 0; i < n-1; i++){
    int a, b; cin >> a >> b;
    g[--a].push_back(--b);
    g[b].push_back(a);
  }

  for(int i = 0; i < n-1; i++){
    int a, b; cin >> a >> b;
    h[--a].push_back(--b);
    h[b].push_back(a);
  }

  cout << (f(0, -1, g) == f(0, -1, h) ? "YES\n" : "NO\n");
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int t; cin >> t;
  while(t--) solve();
}