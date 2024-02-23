#include <bits/stdc++.h>
using namespace std;

struct st{
  int sz = 1;
  vector<long long> v;

  st(int n){
    while(sz < n) sz *= 2;
    v.resize(2*sz, -1e18);
  }

  void upd(int u, long long t){
    u += sz; u = min(u, (int)v.size()-1);
    if(v[u] >= t) return;

    v[u] = t;
    while(u > 1){
      u /= 2;
      v[u] = max(v[2*u], v[2*u+1]);
    }
  }

  int get(int u, int l, int r, long long t){
    if(l == r-1) return l;

    if(v[2*u] >= t) return get(2*u, l, (l+r)/2, t);
    else return get(2*u+1, (l+r)/2, r, t);
  }
};

long long stalkera(int n, int k, vector<int> s){
  long long temp = 0;
  for(auto i : s) temp += i;
  if(temp <= 0) return temp;

  vector<long long> cum(n+1); cum[0] = 0;
  for(int i = 1; i <= n; i++) cum[i] = cum[i-1] + s[i-1];

  st st(n+2);

  auto test = [&](long long per){
    for(auto &i : st.v) i = -1e18;
    st.upd(0, 0); st.upd(n+1, 1e18);

    for(int i = 1; i <= n; i++){
      int ans = st.get(1, 0, st.sz, cum[i]-per)+1;
      if(i == n) return (ans <= k);
      st.upd(ans, cum[i]);
    }
  };

  long long l = 0, r = temp+1;
  while(l < r-1){
    long long m = l + (r-l)/2;

    if(test(m)) r = m;
    else l = m;
  }

  return l+1;
}