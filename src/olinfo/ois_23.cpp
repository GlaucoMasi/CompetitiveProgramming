#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  
  vector<int> p3(17); p3[0] = 1;
  for(int i = 1; i < 17; i++) p3[i] = p3[i-1]*3;

  auto c3 = [&](int i){
    int sum = 0;

    for(int j = 16; j >= 0; j--){
      while(i >= p3[j]){
        i -= p3[j];
        sum++;
      }
    }

    return sum;
  };

  vector<int> prec(p3[9]);
  for(int i = 0; i < p3[9]; i++) prec[i] = c3(i);

  vector<int> spec;
  for(int i = 1; i <= 1e8; i++) if(__builtin_popcount(i) == prec[i%p3[9]]+prec[i/p3[9]]) spec.push_back(i);
  
  int t; cin >> t;
  vector<int> ans(t);
  vector<pair<int, int>> quer(t);
  for(int i = 0; i < t; i++){
    cin >> quer[i].first;
    quer[i].second = i;
  }

  int idx = 0;
  sort(quer.begin(), quer.end());
  for(auto [n, i] : quer){
    while(spec[idx] <= n) idx++;
    ans[i] = idx;
  }

  for(auto i : ans) cout << i << " ";
}