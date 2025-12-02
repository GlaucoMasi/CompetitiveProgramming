#include <bits/stdc++.h>
using namespace std;

int main() {
  string a, b;
  vector<pair<long long, long long>> intervs;
  while(getline(cin, a, '-')) {
    getline(cin, b, ',');
    intervs.push_back({stoll(a), stoll(b)});
  }

  vector<long long> ps(17); ps[0] = 1;
  for(int i = 1; i < ps.size(); i++) ps[i] = ps[i-1] * 10;

  int l = 0;
  long long ans = 0;
  sort(intervs.begin(), intervs.end());

  vector<long long> check;
  for(long long i = 1; i < 1e6; i++) {
    long long x = i;
    int length = (int)log10(i)+1;
    for(int k = 2; k*length < 12; k++) {
      x += i * ps[length * (k-1)];
      check.push_back(x);
    }
  }

  sort(check.begin(), check.end());
  check.resize(unique(check.begin(), check.end())-check.begin());
  for(auto x : check) {
    while(l < intervs.size() && intervs[l].second < x) l++;
    if(x >= intervs[l].first && x <= intervs[l].second) ans += x;
  }

  cout << ans;
}