#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n;
  unordered_map<int, int> m;
  long long tot = 0;

  for(int i = 0; i < n; i++){
    int a; long long k; char c;
    cin >> a >> c >> k;

    tot += a;
    if(m.count(c)) m[c] += a;
    else m[c] = a;

    vector<long long> v;
    for(auto i : m) v.push_back(i.second);
    sort(v.begin(), v.end());

    long long ans = tot*tot;
    for(int i = 0; i < v.size(); i++){
      int off = min(k, v[i]);
      v[i] -= off; k -= off; v[v.size()-1] += off;

      ans -= v[i]*v[i];
    }

    cout << ans/2 << '\n';
  }
}

int main() {
  int t; cin >> t;
  while(t--) solve();
}