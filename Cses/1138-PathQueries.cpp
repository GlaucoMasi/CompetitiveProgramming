#include <bits/stdc++.h>
using namespace std;
 
struct ST{
  int size = 1;
  vector<long long> v;
 
  void init(int n){
    while(size < n) size *= 2;
    v.resize(2*size);
  }
 
  void upd(int u, int val){
    u += size;
    v[u] = val;
 
    while(u > 1){
      u /= 2;
      v[u] = v[2*u]+v[2*u+1];
    }
  }
 
  long long query(int u, int l, int r, int x, int y){
    if(l >= y || r <= x) return 0;
    if(l >= x && r <= y) return v[u];
    return query(2*u, l, l + (r-l)/2, x, y) + query(2*u+1, l + (r-l)/2, r, x, y);
  }
};
 
ST st;
int n, q;
vector<vector<int>> g;
 
vector<int> ord, value;
vector<pair<int, int>> idx;
 
void f(int i, int fat){
  ord.push_back(i);
  for(auto j : g[i]) if(j != fat) f(j, i);
  ord.push_back(i);
}
 
int main() {
  cin >> n >> q;
  g.resize(n);
  idx.resize(n, {-1, -1});
  value.resize(n);
 
  st.init(2*n);
 
  for(auto &i : value) cin >> i;
 
  for(int i = 0; i < n-1; i++){
    int a, b; cin >> a >> b;
    a--; b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }
 
  f(0, 0);
 
  for(int i = 0; i < 2*n; i++){
    int prod = 1;
    
    if(idx[ord[i]].first != -1){
      idx[ord[i]].second = i;
      prod = -1;
    }else idx[ord[i]].first = i;
  
    st.upd(i, value[ord[i]]*prod); 
  }
 
  while(q--){
    int a; cin >> a;
 
    if(a == 1){
      int b, c; cin >> b >> c; b--;
 
      st.upd(idx[b].first, c);
      st.upd(idx[b].second, -c);
    }else{
      int b; cin >> b; b--;
      cout << st.query(1, 0, st.size, 0, idx[b].first+1) << endl;
    }
  }
}