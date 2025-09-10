#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n, k; cin >> n >> k;
  vector<int> v(n); for(auto &i : v) cin >> i;
  sort(v.begin(), v.end());
  pair<int, int> best = max(make_pair(v[0], 0), make_pair(k-v.back(), k));
  for(int i = 0; i < n-1; i++) best = max(best, {(v[i+1]-v[i])/2, (v[i]+v[i+1])/2});
  cout << best.second;
}