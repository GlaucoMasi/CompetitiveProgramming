#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int n, m, k;
vector<vector<int>> g;
vector<bool> sup;

vector<int> calc(int i){
  vector<int> ans(n, -1);
  queue<pair<int, int>> q;
  
  q.push({i, 0});
  while(!q.empty()){
    auto curr = q.front(); q.pop();

    if(ans[curr.first] != -1) continue;
    ans[curr.first] = curr.second;

    for(auto i : g[curr.first]) q.push({i, curr.second+1});
  }

  return ans;
}

int main() {
  fin >> n >> m >> k;

  int a, b;
  vector<int> sup;
  while(k--){
    fin >> a; a--;
    sup.push_back(a);
  }

  g.resize(n);
  while(m--){
    fin >> a >> b; a--; b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  int ans = 1e9;
  vector<int> start = calc(0), end = calc(n-1);
  for(auto i : sup) ans = min(ans, start[i]+end[i]);
  fout << ans;
}