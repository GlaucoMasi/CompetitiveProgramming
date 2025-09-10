#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  int n; cin >> n;
  vector<int> v(n); for(auto &i : v) cin >> i;

  vector<int> left(n);
  vector<pair<int, int>> s; s.push_back({0, -1});
  for(int i = 0; i < n; i++){
    while(s.back().first >= v[i]) s.pop_back();
    left[i] = s.back().second;
    s.push_back({v[i], i});
  }

  long long best = 0;
  s.clear(); s.push_back({0, n});
  for(int i = n-1; i >= 0; i--){
    while(s.back().first >= v[i]) s.pop_back();
    best = max(best, (long long)v[i]*(s.back().second-left[i]-1));
    s.push_back({v[i], i});
  }

  cout << best;
}