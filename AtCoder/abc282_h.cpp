#include <bits/stdc++.h>
using namespace std;

struct st{
  int sz = 1;
  vector<pair<long long, int>> v;

  st(vector<long long> &data){
    while(sz < data.size()) sz *= 2;
    v.resize(2*sz, {1e18, -1});
    build(1, 0, sz, data);
  }

  void build(int u, int l, int r, vector<long long> &data){
    if(l == r-1){
      if(l < data.size()) v[u] = {data[l], l};
    }else{
      build(2*u, l, (l+r)/2, data);
      build(2*u+1, (l+r)/2, r, data);
      v[u] = min(v[2*u], v[2*u+1]);
    }
  }

  pair<long long, int> get(int u, int l, int r, int x, int y){
    if(l >= y || r <= x) return {1e18, -1};
    if(l >= x && r <= y) return v[u];

    return min(
      get(2*u, l, (l+r)/2, x, y),
      get(2*u+1, (l+r)/2, r, x, y)
    );
  }
};

int main() {
  int n; long long s;
  cin >> n >> s;
  vector<long long> a(n), b(n);
  for(auto &i : a) cin >> i;
  for(auto &i : b) cin >> i;

  vector<long long> cum(n+1);
  for(int i = 1; i <= n; i++) cum[i] = cum[i-1]+b[i-1];

  st st(a);

  long long ans = 0;
  auto solve1 = [&](int l1, int r1, int m1, long long t){
    for(int i = l1; i <= m1; i++){
      long long sum = t + cum[i-1];
      int r = upper_bound(cum.begin(), cum.end(), sum) - cum.begin() - 1;
      r = min(r, r1);
      ans += max(0, r-m1+1);
    }
  };

  auto solve2 = [&](int l1, int r1, int m1, long long t){
    for(int i = m1; i <= r1; i++){
      long long sum = cum[i] - t;
      int l = lower_bound(cum.begin(), cum.end(), sum) - cum.begin() + 1;
      l = max(l, l1);
      ans += max(0, m1-l+1);
    }
  };

  vector<pair<int, int>> interv; interv.push_back({1, n});
  while(!interv.empty()){
    vector<pair<int, int>> next;

    for(auto [l, r] : interv){
      auto t = st.get(1, 0, st.sz, l-1, r);
      int m = t.second+1; long long sum = s-t.first;

      if(m-l < r-m) solve1(l, r, m, sum);
      else solve2(l, r, m, sum);
    
      if(l <= m-1) next.push_back({l, m-1});
      if(m+1 <= r) next.push_back({m+1, r});
    }

    interv = next;
  }

  cout << ans;
}