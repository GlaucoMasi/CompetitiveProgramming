#include <bits/stdc++.h>
using namespace std;

struct st{
  int sz = 1;
  vector<int> v;

  st(vector<int> &data){
    while(sz < data.size()) sz *= 2;
    v.resize(2*sz); data.resize(sz);
    build(1, 0, sz, data);
  }

  void build(int u, int l, int r, vector<int> &data){
    if(l == r-1) v[u] = data[l];
    else{
      build(2*u, l, (l+r)/2, data);
      build(2*u+1, (l+r)/2, r, data);
      v[u] = max(v[2*u], v[2*u+1]);
    }
  }

  void upd(int u, int k){
    u += sz;
    v[u] -= k;

    while(u > 1){
      u /= 2;
      v[u] = max(v[2*u], v[2*u+1]);
    }
  }

  int get(int u, int l, int r, int k){
    if(l == r-1) return l;

    if(v[2*u] >= k) return get(2*u, l, (l+r)/2, k);
    else return get(2*u+1, (l+r)/2, r, k);
  }
};

int main() {
  int n, m; cin >> n >> m;
  vector<int> v(n); for(auto &i : v) cin >> i;
  v.push_back(2e9);
  st st(v);

  for(int i = 0; i < m; i++){
    int k; cin >> k;
    int idx = st.get(1, 0, st.sz, k);
    if(idx == n) cout << 0 << " ";
    else{
      cout << idx+1 << " ";
      st.upd(idx, k);
    }
  }
}