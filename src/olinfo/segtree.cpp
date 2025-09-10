#include <bits/stdc++.h>
using namespace std;

int size = 1;

struct ST{
  struct Node{
    long long sum = 0, min = 0, lazy = 0;
    bool settare = 0;

    void join(const Node &r, const Node &l){
      sum = r.sum + l.sum;
      min = std::min(l.min, r.min);
    }
  };

  vector<Node> v;
  void init(vector<long long> &data){
    int n = data.size();
    while(size < n) size *= 2;
    v.resize(2*size, Node());

    build(1, 0, size, data);
  }

  void build(int u, int l, int r, vector<long long> &data){
    if(l == r-1){
      if(l < data.size()) v[u].sum = v[u].min = data[l];
    }else{
      build(2*u, l, l + (r-l)/2, data);
      build(2*u+1, l + (r-l)/2, r, data);
      v[u].join(v[2*u], v[2*u+1]);
    }
  }

  void passa(int u, int l, int r){
    if(v[u].settare){
      if(l != r-1){
        v[2*u].settare = v[2*u+1].settare = 1;
        v[2*u].lazy = v[2*u+1].lazy = v[u].lazy;
      }

      v[u].min = v[u].lazy;
      v[u].sum = v[u].lazy * (r-l);
      v[u].lazy = v[u].settare = 0;
    }else{
      if(l != r-1){
        v[2*u].lazy += v[u].lazy;
        v[2*u+1].lazy += v[u].lazy;
      }

      v[u].min += v[u].lazy;
      v[u].sum += v[u].lazy * (r-l);
      v[u].lazy = 0;
    }
  }

  void add(int u, int l, int r, int x, int y, long long t){
    passa(u, l, r);
    if(l >= y || r <= x) return;
    if(l >= x && r <= y){
      v[u].lazy += t;
      passa(u, l, r);
      return;
    }

    add(2*u, l, l + (r-l)/2, x, y, t);
    add(2*u+1, l + (r-l)/2, r, x, y, t);
    v[u].join(v[2*u], v[2*u+1]);
  }

  void set(int u, int l, int r, int x, int y, long long t){
    passa(u, l, r);
    if(l >= y || r <= x) return;
    if(l >= x && r <= y){
      v[u].lazy = t;
      v[u].settare = 1;
      passa(u, l, r);
      return;
    }

    set(2*u, l, l + (r-l)/2, x, y, t);
    set(2*u+1, l + (r-l)/2, r, x, y, t);
    v[u].join(v[2*u], v[2*u+1]);
  }

  long long get_sum(int u, int l, int r, int x, int y){
    passa(u, l, r);
    if(l >= y || r <= x) return 0;
    if(l >= x && r <= y) return v[u].sum;

    return get_sum(2*u, l, l + (r-l)/2, x, y) + get_sum(2*u+1, l + (r-l)/2, r, x, y);
  }

  long long get_min(int u, int l, int r, int x, int y){
    passa(u, l, r);
    if(l >= y || r <= x) return 9e18;
    if(l >= x && r <= y) return v[u].min;

    return std::min(get_min(2*u, l, l + (r-l)/2, x, y), get_min(2*u+1, l + (r-l)/2, r, x, y));
  }

  int lb(int u, int l, int r, int x, int y, long long t){
    passa(u, l, r);


    if(l >= y || r <= x) return -1;
    if(l >= x && r <= y){
      if(l == r-1){
        if(v[u].sum <= t) return l;
        else return -1;
      }

      if(l != r-1){
        passa(2*u, l, l + (r-l)/2);
        passa(2*u+1, l + (r-l)/2, r);
      }
      
      if(v[2*u].min <= t) return lb(2*u, l, l + (r-l)/2, x, y, t);
      else if(v[2*u+1].min <= t) return lb(2*u+1, l + (r-l)/2, r, x, y, t);
      else return -1;
    }

    int a = lb(2*u, l, l + (r-l)/2, x, y, t);
    if(a != -1) return a;
    else return lb(2*u+1, l + (r-l)/2, r, x, y, t);
  }
};

ST st;

void init(vector<long long> a){ st.init(a); }

void add(int l, int r, long long x){ st.add(1, 0, size, l, r, x); }

void set_range(int l, int r, long long x){ st.set(1, 0, size, l, r, x); }

long long get_sum(int l, int r){ return st.get_sum(1, 0, size, l, r); }

long long get_min(int l, int r){ return st.get_min(1, 0, size, l, r); }

int lower_bound(int l, int r, long long x){ int a = st.lb(1, 0, size, l, r, x); int i; while(a == 0) i++; return a; }