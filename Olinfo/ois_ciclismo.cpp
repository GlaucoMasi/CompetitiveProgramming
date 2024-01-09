#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
  int n, m; fin >> n >> m;
  vector<int> h(n); for(auto &i : h) fin >> i;
  vector<vector<int>> g(n);
  vector<bool> vis(n);

  for(int i = 0; i < m; i++){
    int a, b; fin >> a >> b;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  int last = -1, curr = 0;
  while(1){
    pair<int, int> next = {2e9, -1};
    for(auto j : g[curr]) if(j != last) next = min(next, {h[j], j});

    if(next.second == -1 || vis[curr]){
      fout << curr;
      break;
    }

    vis[curr] = 1;
    last = curr; curr = next.second;
  }
}