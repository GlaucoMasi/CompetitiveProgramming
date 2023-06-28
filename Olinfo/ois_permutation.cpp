#include <bits/stdc++.h>
using namespace std;

struct ST{
  int size = 1;
  vector<int> v;

  void init(int n){
    while(size < n) size *= 2;

    v.clear();
    v.resize(2*size);
  }

  void upd(int u){
    u += size;
    v[u] = 1;

    while(u > 1){
      u /= 2;
      v[u] = v[2*u]+v[2*u+1];
    }
  }

  int get(int u, int l, int r, int x, int y){
    if(l >= y || r <= x) return 0;
    if(l >= x && r <= y) return v[u];
    return get(2*u, l, l + (r-l)/2, x, y) + get(2*u+1, l + (r-l)/2, r, x, y);
  }
};

ST st;

void solve(){
  int n; cin >> n;
  vector<int> idx(n);

  st.init(n);

  int best = 0;
  for(int i = 0; i < n; i++){
    int a; cin >> a; a--;
    idx[a] = i;
    best += st.get(1, 0, st.size, a+1, n);
    st.upd(a);
  }

  int next = best;
  for(int i = 0; i < n; i++) best = min(best, next += n-1-2*idx[i]);

  cout << best << '\n';
}

int main() {
  int t; cin >> t;
  while(t--) solve();
}