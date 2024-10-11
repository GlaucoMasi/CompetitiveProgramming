#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

struct st{
  int sz = 1;
  vector<int> v;

  st(int n){
    while(sz < n) sz *= 2;
    v.resize(2*sz);
  }

  void upd(int u, int x){
    if(v[u+=sz] >= x) return;
    v[u] = x;

    while(u > 1){
      u /= 2;
      v[u] = max(v[2*u], v[2*u+1]);
    }
  }

  int get(int u, int l, int r, int y){
    if(l >= y) return 0;
    if(r <= y) return v[u];
    return max(
      get(2*u, l, (l+r)/2, y),
      get(2*u+1, (l+r)/2, r, y)
    );
  }
};

int main() {
  int n; cin >> n;
  vector<pair<int, int>> v(n);
  for(auto &[a, b] : v) cin >> a >> b;
  sort(v.begin(), v.end());

  vector<int> vals;
  for(auto [a, b] : v) vals.push_back(a), vals.push_back(b);
  sort(vals.begin(), vals.end());
  vals.resize(unique(vals.begin(), vals.end())-vals.begin());

  unordered_map<int, int> m;
  for(int i = 0; i < vals.size(); i++) m[vals[i]] = i;

  st st(vals.size());
  for(auto &[a, b] : v){
    a = m[a], b = m[b];
    int t = st.get(1, 0, st.sz, a+1)+1;
    st.upd(b, t);
  }

  cout << st.v[1];
}