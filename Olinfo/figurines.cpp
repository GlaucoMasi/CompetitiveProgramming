#include <bits/stdc++.h>
using namespace std;

int n;

struct ST{
  struct nodes{
    int val = 0, day = 0;
    int r, l;
  };

  int size = 1, curr = 0;
  vector<nodes> v;
  vector<int> roots;

  void init(int n){
    while(size < n) size *= 2;
    v.resize(4e6);
    roots.push_back(build(0, size));
  }

  int get() { return curr++; }

  int build(int l, int r){
    int i = get();
    
    if(l != r-1){
      v[i].l = build(l, l + (r-l)/2);
      v[i].r = build(l + (r-l)/2, r);
    }

    return i;
  }

  int upd(int u, int l, int r, int x, int k, int day){
    if(l > x || r <= x) return u;

    if(v[u].day != day){
      int i = get();
      v[i] = v[u];
      v[i].day = day;
      u = i;
    }

    if(l != r-1){
      v[u].l = upd(v[u].l, l, l + (r-l)/2, x, k, day);
      v[u].r = upd(v[u].r, l + (r-l)/2, r, x, k, day);
      v[u].val = v[v[u].l].val + v[v[u].r].val;
    }else v[u].val = k;

    return u;
  }

  void create(int day) {
    int i = get();
    v[i] = v[roots.back()];
    v[i].day = day;
    roots.push_back(i);
  }

  int get(int u, int l, int r, int x, int y){
    if(l >= y || r <= x) return 0;
    if(l >= x && r <= y) return v[u].val;

    return get(v[u].l, l, l + (r-l)/2, x, y) + get(v[u].r, l + (r-l)/2, r, x, y);
  }

  void update(int pos, int k, int day){ upd(roots.back(), 0, size, pos, k, day); }
  int ans(int d, int x){ return get(roots[d], 0, size, x, n+1); }
};

int day = 1;
ST st;

void init(int N){
  n = N;
  st.init(n);
}

void log(vector<int>& added, vector<int>& removed){
  st.create(day);

  for(auto i : added) st.update(i, 1, day);
  for(auto i : removed) st.update(i, 0, day);

  day++;
}

int answer(int d, int x){ return st.ans(d, x); }