#include <bits/stdc++.h>
using namespace std;

vector<int> p, logs;
vector<pair<int, int>> v;

void solve(int n, int idx) {
  if(!(n%4)) cout << n << " " << p[(logs[idx]+1)]-1 << '\n';
  else if(!((n+1)%4)) cout << 0 << " " << (n^0) << '\n';
  else if(!((n+2)%4)) cout << n+1 << " " << p[(logs[idx]+1)]-1 << '\n';
  else cout << 1 << " " << n << '\n';
}

int main() {
  p.resize(32); p[0] = 1;
  for(int i = 1; i < 32; i++) p[i] = 2*p[i-1];

  int t; cin >> t;
  for(int i = 0; i < t; i++){
    int a; cin >> a;
    v.push_back({a, i});
  }
  sort(v.begin(), v.end());
  logs.resize(t);

  int idx = 0;
  for(int i = 0; i < t; i++){
    while(p[idx+1] <= v[i].first) idx++;
    logs[v[i].second] = idx;
  }

  sort(v.begin(), v.end(), [&](pair<int, int> a, pair<int, int> b) { return a.second < b.second; });

  for(auto i : v) solve(i.first, i.second);
}