#include <bits/stdc++.h>
using namespace std;

struct st{
  struct node{
    int plus = 2e9, minus = 2e9;

    void join(const node &l, const node &r){
      plus = min(l.plus, r.plus);
      minus = min(l.minus, r.minus);
    }
  };

  int size = 1;
  vector<node> v;

  st(vector<int> &data){
    while(size < data.size()) size *= 2;
    v.resize(2*size, node());

    build(1, 0, size, data);
  }

  void build(int u, int l, int r, vector<int> &data){
    if(l == r-1){
      if(l < data.size()){
        v[u].plus = data[l]+l;
        v[u].minus = data[l]-l;
      }
    }else{
      build(2*u, l, l + (r-l)/2, data);
      build(2*u+1, l + (r-l)/2, r, data);

      v[u].join(v[2*u], v[2*u+1]);
    }
  }

  void update(int pos, int k){
    int u = pos + size;
    v[u].minus = k-pos;
    v[u].plus = k+pos;

    while(u > 1){
      u /= 2;
      v[u].join(v[2*u], v[2*u+1]);
    }
  }

  int left(int u, int l, int r, int x, int y){
    if(l >= y || r <= x) return 2e9;
    if(l >= x && r <= y) return v[u].minus;

    return min(
      left(2*u, l, l + (r-l)/2, x, y), 
      left(2*u+1, l + (r-l)/2, r, x, y)
    );
  }

  int right(int u, int l, int r, int x, int y){
    if(l >= y || r <= x) return 2e9;
    if(l >= x && r <= y) return v[u].plus;

    return min(
      right(2*u, l, l + (r-l)/2, x, y), 
      right(2*u+1, l + (r-l)/2, r, x, y)
    );
  }

  int query(int i){
    return min(left(1, 0, size, 0, i)+i, right(1, 0, size, i, size)-i);
  }
};

int main() {
  int n, q; cin >> n >> q;
  vector<int> v(n);
  for(auto &i : v) cin >> i;

  st st(v);

  int a, b, c;
  while(q--){
    cin >> a;

    if(a == 1){
      cin >> b >> c;
      st.update(b-1, c);
    }else{
      cin >> b;
      cout << st.query(b-1) << endl;
    }
  }
}