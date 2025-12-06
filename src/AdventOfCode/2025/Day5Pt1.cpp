#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  
  vector<pair<long long, long long>> ranges;
  while(getline(cin, s) && !s.empty()) {
    int idx = s.find('-');
    ranges.push_back({stoll(s.substr(0, idx)), stoll(s.substr(idx+1))});
  }
  sort(ranges.begin(), ranges.end());

  vector<long long> vals;
  while(cin >> s) {
    vals.push_back(stoll(s));
  }
  sort(vals.begin(), vals.end());

  int ans = 0, j = 0;
  for(auto i : vals) {
    while(j < ranges.size() && ranges[j].second < i) j++;
    ans += (j != ranges.size() && ranges[j].first <= i);
  }

  cout << ans;
}