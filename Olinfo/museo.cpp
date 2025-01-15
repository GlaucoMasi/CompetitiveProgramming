#include <vector>
using namespace std;

int sz = 1;
vector<int> v;

void build(int u, int l, int r, vector<int> &a){
  if(l == r-1) v[u] = a[l];
  else{
    build(2*u, l, (l+r)/2, a);
    build(2*u+1, (l+r)/2, r, a);
    v[u] = max(v[2*u], v[2*u+1]);
  }
}

int get(int u, int l, int r, int x, int y){
  if(l >= y || r <= x) return 0;
  if(l >= x && r <= y) return v[u];
  return max(
    get(2*u, l, (l+r)/2, x, y),
    get(2*u+1, (l+r)/2, r, x, y)
  );
}

void inizia(int n, vector<int> a) {
  while(sz < n) sz *= 2;
  a.resize(sz);
  v.resize(2*sz);
  build(1, 0, sz, a);
}

void aggiorna(int u, int k) {
  u += sz;
  v[u] = k;

  while(u > 1){
    u /= 2;
    v[u] = max(v[2*u], v[2*u+1]);
  }
}

int massimo(int l, int r) {
  return get(1, 0, sz, l, r+1);
}