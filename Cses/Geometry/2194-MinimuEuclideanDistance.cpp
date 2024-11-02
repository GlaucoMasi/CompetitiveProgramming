#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  int n; cin >> n;
  vector<pair<long long, long long>> v(n);
  for(auto &[a, b] : v) cin >> a >> b;
  sort(v.begin(), v.end());

  int j = 0;
  int64_t best = 8e18;
  set<pair<long long, long long>> s;
  for(int i = 0; i < n; i++){
    long long d = ceil(sqrtl(best));
    while(v[j].first < v[i].first-d){
      s.erase({v[j].second, v[j].first});
      j++;
    }

    auto t1 = s.lower_bound({v[i].second-d, -1e9});
    auto t2 = s.upper_bound({v[i].second+d, -1e9});
  
    while(t1 != t2){
      long long x = v[i].first-t1->second;
      long long y = v[i].second-t1->first;
      best = min(best, (int64_t)(x*x+y*y));
      t1++;
    }

    s.insert({v[i].second, v[i].first});
  }

  cout << best;
}