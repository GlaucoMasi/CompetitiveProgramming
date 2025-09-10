#include <bits/stdc++.h>
using namespace std;

struct ST{
  struct Node{
    int val = 1e9;

    void join(const Node &l, const Node &r){
      val = min(l.val, r.val);
    }
  };

  int size = 1;
  vector<Node> v;

  void init(vector<int> &data){
    while(size < data.size()) size *= 2;
    v.resize(2*size, Node());

    build(1, 0, size, data);
  }

  void build(int u, int l, int r, vector<int> &data){
    if(l == r-1){
      if(l < data.size()) v[u].val = data[l];
    }else{
      build(2*u, l, l + (r-l)/2, data);
      build(2*u+1, l + (r-l)/2, r, data);
      v[u].join(v[2*u], v[2*u+1]);
    }
  }
  
  void update(int pos, int k){
    int u = size + pos;
    v[u].val = k;

    while(u != 1){
      u /= 2;
      v[u].join(v[2*u], v[2*u+1]);
    }
  }

  int query(int u, int l, int r, int x, int y){
    if(l >= y || r <= x) return 1e9;
    if(l >= x && r <= y) return v[u].val;

    return min(query(2*u, l, l + (r-l)/2, x, y), query(2*u+1, l + (r-l)/2, r, x, y));
  }
};

int main() {
  ST st;
  int n, q; cin >> n >> q;
  vector<int> v(n);
  for(auto &i : v) cin >> i;
  st.init(v);

  int a, b, c;
  while(q--){
    cin >> c >> a >> b;
    a--;

    if(c == 1) st.update(a, b);
    if(c == 2) cout << st.query(1, 0, st.size, a, b) << endl;
  }
}