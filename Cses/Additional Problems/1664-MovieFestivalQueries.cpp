#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");
 
struct st{
  int sz = 1;
  vector<int> v;
 
  st(int n){
    while(sz < n) sz *= 2;
    v.resize(2*sz, 1e9);
  }
 
  void upd(int u, int k){
    u += sz;
    v[u] = k;
 
    while(u > 1){
      u /= 2;
      v[u] = min(v[2*u], v[2*u+1]);
    }
  }
 
  int get(int u, int l, int r, int x, int y){
    if(l >= y || r <= x) return 1e9;
    if(l >= x && r <= y) return v[u];
 
    return min(
      get(2*u, l, (l+r)/2, x, y),
      get(2*u+1, (l+r)/2, r, x, y)
    );
  }
};
 
int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
  int n, q; cin >> n >> q;
  vector<pair<int, int>> v(n);
  for(auto &[a, b] : v) cin >> b >> a;
 
  vector<pair<int, int>> quer(q);
  for(auto &[a, b] : quer) cin >> a >> b;

  st st(1e6+5);
  sort(v.begin(), v.end());
 
  vector<vector<int>> nxt(n, vector<int>(25, -1));
  for(int i = n-1; i >= 0; i--){
    int idx = st.get(1, 0, st.sz, v[i].first, st.sz);
    if(idx == 1e9) idx = -1;
 
    nxt[i][0] = idx;
    for(int j = 1; j < 25; j++){
      if(nxt[i][j-1] == -1) break;
      nxt[i][j] = nxt[nxt[i][j-1]][j-1];
    }
 
    st.upd(v[i].second, i);
  }
 
  for(auto [l, r] : quer){
    int start = st.get(1, 0, st.sz, l, st.sz);
 
    if(start == 1e9 || v[start].first > r) cout << "0\n";
    else{
      int skip = 0;
      for(int j = 24; j >= 0; j--){
        if(nxt[start][j] != -1 && v[nxt[start][j]].first <= r){
          skip += (1<<j);
          start = nxt[start][j];
        }
      }
 
      cout << skip+1 << '\n';
    }
  }
}