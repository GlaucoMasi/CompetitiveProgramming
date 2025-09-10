#include <bits/stdc++.h>
using namespace std;

struct st{
  struct node{
    long long sum = 0, pref = 0;
  
    void assign(long long k){
      sum = k;
      pref = max(k, 0LL);
    }

    void merge(const node &l, const node &r){
      sum = l.sum+r.sum;
      pref = max({0LL, l.pref, l.sum+r.pref});
    }
  };

  int sz = 1;
  vector<node> v;
  st(vector<long long> &data){
    while(sz < data.size()) sz *= 2;
    v.resize(2*sz); data.resize(sz);
    build(1, 0, sz, data);
  }

  void build(int u, int l, int r, vector<long long> &data){
    if(l == r-1) v[u].assign(data[l]);
    else{
      build(2*u, l, (l+r)/2, data);
      build(2*u+1, (l+r)/2, r, data);
      v[u].merge(v[2*u], v[2*u+1]);
    }
  }

  pair<long long, long long> get(int u, int l, int r, int x, int y){
    if(l >= y || r <= x) return {0, -1e18};
    if(l >= x && r <= y) return {v[u].sum, v[u].pref};
    
    auto [suml, prefl] = get(2*u, l, (l+r)/2, x, y);
    auto [sumr, prefr] = get(2*u+1, (l+r)/2, r, x, y);
    return {suml+sumr, max({0LL, prefl, suml+prefr})};
  }

  void upd(int u, int k){
    u += sz; v[u].assign(k);
    while(u > 1){
      u /= 2;
      v[u].merge(v[2*u], v[2*u+1]);
    }
  }
};

int main() {
  int n, q; cin >> n >> q;
  vector<long long> v(n); for(auto &i : v) cin >> i;

  st st(v);
  while(q--){
    int a, b, c; cin >> a >> b >> c;
    if(a == 1) st.upd(b-1, c);
    else cout << st.get(1, 0, st.sz, b-1, c).second << '\n';
  }
}