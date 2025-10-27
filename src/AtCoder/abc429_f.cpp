#include <bits/stdc++.h>
using namespace std;

#define INF 1000000000

using SS = array<int, 3>;
using S = array<SS, 3>;

array<S, 9> m;

struct node {
  S val = m[8];

  void join(const node &l, const node &r){
    for(int i = 0; i < 3; i++){
      for(int j = 0; j < 3; j++){
        val[i][j] = INF;
        for(int k = 0; k < 3; k++){
          val[i][j] = min(val[i][j], l.val[i][k] + r.val[k][j]);
        }
      }
    }
  }
};

struct st {
  int sz = 1;
  vector<node> v;

  st(int n, vector<S> &data) {
    while(sz < n) sz *= 2;
    v.resize(2*sz);
    build(1, 0, sz, data);
  }

  void build(int u, int l, int r, vector<S> &data) {
    if(l == r-1) {
      if(l < data.size()) v[u].val = data[l];
      else v[u].val = m[8];
    } else {
      int m = (l+r)/2;
      build(2*u, l, m, data);
      build(2*u+1, m, r, data);
      v[u].join(v[2*u], v[2*u+1]);
    }
  }

  void upd(int x, S val) {
    x += sz;
    v[x].val = val;
    while(x > 1) {
      x /= 2;
      v[x].join(v[2*x], v[2*x+1]);
    }
  }
};

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  int n; cin >> n;
  m[0] = S{SS{0, 1, 2}, SS{1, 0, 1}, SS{2, 1, 0}};
  m[1] = S{SS{INF, INF, INF}, SS{INF, 0, 1}, SS{INF, 1, 0}};
  m[2] = S{SS{0, INF, INF}, SS{INF, INF, INF}, SS{INF, INF, 0}};
  m[3] = S{SS{INF, INF, INF}, SS{INF, INF, INF}, SS{INF, INF, 0}};
  m[4] = S{SS{0, 1, INF}, SS{1, 0, INF}, SS{INF, INF, INF}};
  m[5] = S{SS{INF, INF, INF}, SS{INF, 0, INF}, SS{INF, INF, INF}};
  m[6] = S{SS{0, INF, INF}, SS{INF, INF, INF}, SS{INF, INF, INF}};
  m[7] = S{SS{INF, INF, INF}, SS{INF, INF, INF}, SS{INF, INF, INF}};
  m[8] = S{SS{0, INF, INF}, SS{INF, 0, INF}, SS{INF, INF, 0}};

  vector<int> v(n);
  for(int j = 0; j < 3; j++) for(int i = 0; i < n; i++) {
    char c; cin >> c;
    if(c == '#') v[i] |= (1<<j);
  }

  vector<S> masks(n);
  for(int i = 0; i < n; i++) masks[i] = m[v[i]];

  st seg(n, masks);

  int q; cin >> q;
  while(q--) {
    int r, c; cin >> r >> c; r--; c--;
    v[c] ^= (1<<r);
    seg.upd(c, m[v[c]]);
    int ans = seg.v[1].val[0][2]+n-1;
    if(ans >= INF) ans = -1;
    cout << ans << '\n';
  }
}