#include <bits/stdc++.h>
using namespace std;

long long ans = 0;
vector<vector<pair<int, long long>>> g;
vector<long long> up, in;

void f(int i, int fat){
  long long tot = 0;
  vector<long long> best(2, 0);

  for(auto j : g[i]){
    if(j.first == fat) continue;

    f(j.first, i);
    if(in[j.first] > 0) tot += in[j.first];

    long long t = up[j.first]+j.second-in[j.first];
    if(best[0] < t){
      best[1] = best[0];
      best[0] = t;
    }else if(best[1] < t) best[1] = t;
  }

  up[i] = tot + best[0];
  in[i] = tot + best[0] + best[1];
  ans = max({ans, up[i], in[i]});
}

long long profitto_massimo(int n, int a[], int b[], int w[]){
  g.resize(n);
  up.resize(n, 0);
  in.resize(n, 0);

  for(int i = 0; i < n-1; i++){
    g[a[i]-1].push_back({b[i]-1, w[i]});
    g[b[i]-1].push_back({a[i]-1, w[i]});
  }

  f(0, -1);
  return ans;
}