#include <bits/stdc++.h>
using namespace std;

long long revenue(int n, int k, vector<long long> a){
  long long left = 0;
  vector<pair<long long, long long>> v;

  for(auto i : a){
    if(i >= 0) v.push_back({i, 1});
    else v.push_back({-i, -1});
    left += v.back().second;
  }

  sort(v.begin(), v.end());

  long long curr = 0, ans = 0;
  for(int i = 0; i < a.size(); i++){
    long long last = i ? v[i-1].first : 0;
    curr += (v[i].first-last)*v[i].second;
    curr -= k*(v[i].first-last);
    left -= v[i].second;

    while(i+1 < a.size() && v[i].first == v[i+1].first){
      i++;
      curr += (v[i].first-last)*v[i].second;
      left -= v[i].second;
    }

    curr += (v[i].first-last)*left;
    ans = max(ans, curr);
  }

  return ans;
}