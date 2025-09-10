#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
  int n, m, k; cin >> n >> m >> k;
  vector<int> v(n); for(auto &i : v) cin >> i;
  vector<int> sz(m); for(auto &i : sz) cin >> i;
  sort(v.begin(), v.end()); sort(sz.begin(), sz.end(), greater<>());

  int ans = 0;
  for(auto i : v){
    while(!sz.empty() && sz.back() < i-k) sz.pop_back();
    if(sz.empty()) break;
    if(sz.back() <= i+k){
      sz.pop_back();
      ans++;
    }
  }

  cout << ans;
}