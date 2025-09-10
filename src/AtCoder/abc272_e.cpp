#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
  int n, m; cin >> n >> m;
  vector<ll> v(n);
  for(auto &i : v) cin >> i;

  vector<vector<ll>> pres(m+1);
  for(int i = 1; i <= n; i++){
    ll a = v[i-1];

    ll idx;
    if(a >= 0) idx = 0;
    else idx = ceil(1.0*(-a)/i);

    for(idx; idx <= m && a + idx*i <= n; idx++) pres[idx].push_back(a+idx*i);
  }

  for(int k = 1; k <= m; k++){
    auto i = pres[k];
    sort(i.begin(), i.end());
    i.resize(unique(i.begin(), i.end())-i.begin());
    i.push_back(1e18);

    for(int j = 0; j < i.size(); j++) if(i[j] != j){
      cout << j << '\n';
      break;
    }
  }
}