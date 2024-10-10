#include <bits/stdc++.h>
using namespace std;

int constexpr num = 2e7;

struct st{
  struct node{
    long long val;
    bool create = 0;

    int l = -1, r = -1;
  };

  int size = 1, curr = 0;
  vector<int> roots;
  vector<node> v;

  int get() { return curr++; }

  void passa(int u, int l, int r){
    if(!v[u].create) return;

    if(v[u].l != -1){
      int i = get();
      v[i] = v[v[u].l];
      v[i].create = 1;
      v[u].l = i;
    }

    if(v[u].r != -1){
      int i = get();
      v[i] = v[v[u].r];
      v[i].create = 1;
      v[u].r = i;
    }

    v[u].create = 0;
  }

  void init(int n, vector<int> &data){
    while(size < n) size *= 2;
    data.resize(size);
    v.resize(num, node());

    roots.push_back(build(0, size, data));
  }

  int build(int l, int r, vector<int> &data){
    int i = get();
    
    if(l == r-1){
      v[i].val = data[l];
    }else{
      v[i].l = build(l, l + (r-l)/2, data);
      v[i].r = build(l + (r-l)/2, r, data);

      v[i].val = 0;
      if(v[i].l != -1) v[i].val += v[v[i].l].val;
      if(v[i].r != -1) v[i].val += v[v[i].r].val;
    }

    return i;
  }

  void copy(int u){
    int i = get();
    v[i] = v[roots[u]];

    v[i].create = 1;
    roots.push_back(i);
  }

  int update(int u, int l, int r, int x, int k){
    if(u == -1) return -1;
    passa(u, l, r);

    int i = get();
    v[i] = v[u];

    if(l == r-1){
      if(l == x) v[i].val = k;
    }else{
      int m = l + (r-l)/2;
      
      if(m > x) v[i].l = update(v[u].l, l, l + (r-l)/2, x, k);
      else v[i].r = update(v[u].r, l + (r-l)/2, r, x, k);
      
      v[i].val = 0;
      if(v[i].l != -1) v[i].val += v[v[i].l].val;
      if(v[i].r != -1) v[i].val += v[v[i].r].val;
    }

    return i;
  }

  void upd(int k, int l, int x){ roots[k] = update(roots[k], 0, size, l, x); }

  long long get(int u, int l, int r, int x, int y){
    if(u == -1) return 0;
    passa(u, l, r);
    
    if(l >= y || r <= x) return 0;
    if(l >= x && r <= y) return v[u].val;
  
    return get(v[u].l, l, l + (r-l)/2, x, y) + get(v[u].r, l + (r-l)/2, r, x, y);
  }

  long long sum(int k, int x, int y){ return get(roots[k], 0, size, x, y); }
};

int main() {
  int n, q; cin >> n >> q;
  vector<int> v(n);
  for(auto &i : v) cin >> i;

  st st; st.init(n, v);

  while(q--){
    int a, b, c, d; cin >> a;

    if(a == 1){
      cin >> b >> c >> d;
      st.upd(b-1, c-1, d);
    }else if(a == 2){
      cin >> b >> c >> d;
      cout << st.sum(b-1, c-1, d) << endl;
    }else{
      cin >> b;
      st.copy(b-1);
    }
  }
}