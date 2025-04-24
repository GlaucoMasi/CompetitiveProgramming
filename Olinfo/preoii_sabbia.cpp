#include <bits/stdc++.h>
using namespace std;

long long alleggerisci(int n, int m, vector<int> v, vector<int> l, vector<int> r, vector<long long> k){
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  vector<vector<int>> end(n);
  vector<long long> cum(n), done(n);

  cum[0] = v[0];
  for(int i = 1; i < n; i++) cum[i] = cum[i-1]+v[i];
  for(int i = 0; i < m; i++){
    k[i] = cum[r[i]] - (l[i] ? cum[l[i]-1] : 0) - k[i];
    if(k[i] > 0) end[r[i]].push_back(i);
  }

  for(int i = 0; i < n; i++){
    if(i) done[i] = done[i-1];
    for(auto idx : end[i]){
      k[idx] -= done[i] - (l[idx] ? done[l[idx]-1] : 0);
      if(k[idx] > 0) done[i] += k[idx];
    }
  }

  return done.back();
}