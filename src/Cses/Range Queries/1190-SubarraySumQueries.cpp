#include <bits/stdc++.h>
using namespace std;

struct st{
  struct node{
    long long best = 0, pref = 0, suff = 0, sum = 0;

    void merge(const node &l, const node &r){
      sum = l.sum + r.sum;
      pref = max({0LL, l.pref, l.sum+r.pref});
      suff = max({0LL, r.suff, r.sum+l.suff});
      best = max({0LL, l.best, r.best, l.suff+r.pref});
    }

    void assign(int k){
      sum = k;
      best = pref = suff = max(0, k);
    }
  };

  int sz = 1;
  vector<node> v;
  st(vector<int> &data){
    while(sz < data.size()) sz *= 2;
    v.resize(2*sz); data.resize(sz);
    build(1, 0, sz, data);
  }

  void build(int u, int l, int r, vector<int> &data){
    if(l == r-1) v[u].assign(data[l]);
    else{
      build(2*u, l, (l+r)/2, data);
      build(2*u+1, (l+r)/2, r, data);
      v[u].merge(v[2*u], v[2*u+1]);
    }
  }

  void upd(int u, int k){
    u += sz;
    v[u].assign(k);

    while(u > 1){
      u /= 2;
      v[u].merge(v[2*u], v[2*u+1]);
    }
  }
};

int main() {
  int n, m; cin >> n >> m;
  vector<int> v(n); for(auto &i : v) cin >> i;
  st st(v);

  while(m--){
    int k, x; cin >> k >> x;
    st.upd(k-1, x);
    cout << st.v[1].best << '\n';
  }
}