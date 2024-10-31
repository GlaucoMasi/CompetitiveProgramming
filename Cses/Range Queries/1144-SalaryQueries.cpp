#include <bits/stdc++.h>
using namespace std;

struct st{
  int sz = 1;
  vector<int> v;

  st(int n){
    while(sz < n) sz *= 2;
    v.resize(2*sz);
  }

  void upd(int u, int k){
    u += sz;
    v[u] += k;

    while(u > 1){
      u /= 2;
      v[u] += k;
    }
  }

  int get(int u, int l, int r, int x, int y){
    if(l >= y || r <= x) return 0;
    if(l >= x && r <= y) return v[u];
    return get(2*u, l, (l+r)/2, x, y) + get(2*u+1, (l+r)/2, r, x, y);
  }
};

int main() {
  int n, q; cin >> n >> q;
  vector<int> v(n);
  for(auto &i : v) cin >> i;

  vector<int> comp;
  for(auto i : v) comp.push_back(i);

  vector<array<int, 3>> queries;
  for(int i = 0; i < q; i++){
    char c; int a, b;
    cin >> c >> a >> b;

    if(c == '!'){
      comp.push_back(b);
      queries.push_back({0, a, b});
    }else{
      comp.push_back(a);
      comp.push_back(b);
      queries.push_back({1, a, b});
    }
  }

  unordered_map<int, int> m;
  sort(comp.begin(), comp.end());
  comp.resize(unique(comp.begin(), comp.end())-comp.begin());
  for(int i = 0; i < comp.size(); i++) m[comp[i]] = i;
  st st(comp.size());
  
  for(auto &i : v){
    i = m[i];
    st.upd(i, 1);
  }

  for(auto [a, b, c] : queries){
    if(a) cout << st.get(1, 0, st.sz, m[b], m[c]+1) << '\n';
    else{
      st.upd(v[b-1], -1);
      v[b-1] = m[c];
      st.upd(v[b-1], 1);
    }
  }
}