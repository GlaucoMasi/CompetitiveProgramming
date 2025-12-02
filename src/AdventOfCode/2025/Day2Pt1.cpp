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
  for(long long i = 1; l < intervs.size(); i++) {
    long long x = i * (1 + ps[(int)log10(i)+1]);
    while(l < intervs.size() && intervs[l].second < x) l++;
    if(x >= intervs[l].first && x <= intervs[l].second) ans += x;
  }

  cout << ans;
}