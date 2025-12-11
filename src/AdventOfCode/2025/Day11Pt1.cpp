#include <bits/stdc++.h>
using namespace std;

vector<string> ord;
unordered_set<string> vis, nodes;
unordered_map<string, vector<string>> g;

void dfs(string i) {
  vis.insert(i);
  for(auto j : g[i]) if(!vis.count(j)) dfs(j);
  ord.push_back(i);
}

int main() {
  string s;
  while(getline(cin, s)) {
    stringstream ss(s);
    string start; ss >> start;
    start.pop_back(); nodes.insert(start);
    while(ss >> s) {
      g[start].push_back(s);
      nodes.insert(s);
    }
  }

  for(auto i : nodes) if(!vis.count(i)) dfs(i);

  unordered_map<string, int> dp; dp["out"] = 1;
  for(auto i : ord) for(auto j : g[i]) dp[i] += dp[j];
  cout << dp["you"];
}