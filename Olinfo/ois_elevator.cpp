#include <bits/stdc++.h>
using namespace std;

// passa prima di upd

int sz = 262144;
vector<pair<int, int>> v(2*sz, {-1e9, 0});
vector<int> lazy(2*sz);

void build(int u, int l, int r){
  if(l == r-1) v[u] = {0, -l};
  else{
    build(2*u, l, l + (r-l)/2);
    build(2*u+1, l + (r-l)/2, r);
    v[u] = max(v[2*u], v[2*u+1]); 
  }
}

void passa(int u, int l, int r){
  if(!lazy[u]) return;
  
  if(l != r-1){
    v[2*u].first += lazy[u], v[2*u+1].first += lazy[u];
    lazy[2*u] += lazy[u], lazy[2*u+1] += lazy[u];
  }

  lazy[u] = 0;
}

void upd(int u, int l, int r, int x, int y, int k){
  if(l >= y || r <= x) return;
  if(l >= x && r <= y && u != 1){
    v[u].first += k;
    lazy[u] += k;
    return;
  }

  passa(u, l, r);
  upd(2*u, l, l + (r-l)/2, x, y, k);
  upd(2*u+1, l + (r-l)/2, r, x, y, k);
  v[u] = max(v[2*u], v[2*u+1]);
}

void conv(int l, int r, int k){
  if(l <= r) upd(1, 0, sz, l, r, k);
  else upd(1, 0, sz, r+1, l+1, k);
}

int main() {
  int n; cin >> n;
  build(1, 0, sz);

  vector<int> f(n); cin >> f[0];
  for(int i = 1; i < n; i++){
    cin >> f[i];
    conv(f[i-1], f[i], 1);
    if(i == n-1) upd(1, 0, sz, f[i], f[i]+1, 1);
  }

  int q; cin >> q;
  for(int i = 0; i < q; i++){
    int a, b; cin >> a >> b;

    if(a != 0){
      conv(f[a-1], f[a], -1);
      conv(f[a-1], b, 1);

      if(a == n-1){
        upd(1, 0, sz, f[a], f[a]+1, -1);
        upd(1, 0, sz, b, b+1, 1);
      }
    }
    
    if(a != n-1){
      conv(f[a], f[a+1], -1);
      conv(b, f[a+1], 1);
    }

    f[a] = b;
    cout << -v[1].second << " " << v[1].first << '\n';
  }
}