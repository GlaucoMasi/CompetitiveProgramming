#include <bits/stdc++.h>
using namespace std;

int main() {
  int n; long long m, l; cin >> n >> m >> l;
  vector<pair<long long, int>> comp;
  vector<int> v;

  comp.push_back({0, 0});
  comp.push_back({l, 0});

  long long a;
  for(int i = 0; i < n; i++){
    cin >> a;
    comp.push_back({max(a-m, (long long)0), 1});
    comp.push_back({min(a+m+1, l+1), -1});
  }

  sort(comp.begin(), comp.end()); v.push_back(0);
  for(int i = 0; i < comp.size(); i++){
    if(i > 0 && comp[i].first != comp[i-1].first){ v.push_back(0); }

    v[v.size()-1] += comp[i].second;
  }

  int ans = 1e9;
  int curr = 0;
  for(int i = 0; i < v.size(); i++){
    curr += v[i];
    if(i != v.size()-1) ans = min(ans, curr);
  }

  cout << ans;
}