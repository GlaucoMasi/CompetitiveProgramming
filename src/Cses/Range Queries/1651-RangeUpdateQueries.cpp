#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct st{
  struct node{
    ll val = 0, lazy = 0;
  };

  int size = 1;
  vector<node> v;

  st(vector<int> &data){
    while(size < data.size()) size *= 2;
    v.resize(2*size, node());
    data.resize(size);
    build(1, 0, size, data);
  }

  void build(int u, int l, int r, vector<int> &data){
    if(l == r-1) v[u].val = data[l];
    else{
      build(2*u, l, (l+r)/2, data);
      build(2*u+1, (l+r)/2, r, data);
      v[u].val = v[2*u].val + v[2*u+1].val;
    }
  }

  void passa(int u, int l, int r){
    if(!v[u].lazy) return;

    v[u].val += v[u].lazy * (r-l);

    if(l != r-1){
      v[2*u].lazy += v[u].lazy;
      v[2*u+1].lazy += v[u].lazy;
    }

    v[u].lazy = 0;
  }

  void upd(int u, int l, int r, int x, int y, ll k){
    if(l >= y || r <= x) return;
    if(l >= x && r <= y){
      v[u].lazy += k;
      passa(u, l, r);
      return;
    }

    passa(u, l, r);
    upd(2*u, l, (l+r)/2, x, y, k);
    upd(2*u+1, (l+r)/2, r, x, y, k);
    v[u].val = v[2*u].val+v[2*u+1].val;
  }

  ll get(int u, int l, int r, int t){
    passa(u, l, r);

    if(l == r-1) return v[u].val;

    int m = (l+r)/2;
    if(t >= m) return get(2*u+1, m, r, t);
    else return get(2*u, l, m, t);
  }
};

int main() {
  int n, q; cin >> n >> q;
  vector<int> v(n);
  for(auto &i : v) cin >> i;

  st st(v);

  while(q--){
    int t; cin >> t;

    if(t == 1){
      int a, b, c; cin >> a >> b >> c;
      st.upd(1, 0, st.size, a-1, b, c);
    }else{
      int a; cin >> a;
      cout << st.get(1, 0, st.size, a-1) << '\n';
    }
  }
}