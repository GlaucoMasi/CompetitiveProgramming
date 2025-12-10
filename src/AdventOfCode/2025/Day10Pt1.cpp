#include <bits/stdc++.h>
using namespace std;

int solve(stringstream in) {
  int goal = 0;
  string s; in >> s;
  int k = s.size()-2;
  for(int i = 0; i < k; i++) goal += (1<<i)*(s[i+1] == '#');

  int x;
  char trash;
  vector<int> opts;
  while(in >> s && s[0] != '{') {
    opts.push_back(0);
    stringstream ss(s);
    ss >> trash;
    while(ss >> x) {
      opts.back() += (1<<x);
      ss >> trash;
    }
  }

  vector<int> d(1<<k, 1e9);
  queue<pair<int, int>> q; q.push({0, 0});
  while(1) {
    auto [i, dist] = q.front(); q.pop();
    if(i == goal) return dist;
    if(dist >= d[i]) continue;
    d[i] = dist;
    for(auto j : opts) q.push({i^j, dist+1});
  }
}

int main() {
  string s;
  int ans = 0;
  while(getline(cin, s)) ans += solve(stringstream(s));
  cout << ans;
}