#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

const int maxn = 2e5;

struct st{
  struct node{
    long long val = 0, lazyadd = 0, lazyset = 0;
    bool toset = 0;
  };

  vector<node> v;

  st(vector<int> &data){ 
    v.resize(4*maxn);
    build(1, 0, data.size(), data);
  }

  void build(int u, int l, int r, vector<int> &data){
    if(l == r-1){
      if(l < data.size()) v[u].val = data[l];
    }else{
      build(2*u, l, (l+r)/2, data);
      build(2*u+1, (l+r)/2, r, data);
      v[u].val = v[2*u].val + v[2*u+1].val;
    }
  }

  void appladd(int u, int k){
    if(v[u].toset) v[u].lazyset += k;
    else v[u].lazyadd += k;
  }

  void applset(int u, int k){
    v[u].lazyadd = 0;
    v[u].lazyset = k;
    v[u].toset = 1;
  }

  void add(int u, int l, int r, int x, int y, int k){
    passa(u, l, r);
    if(l >= y || r <= x) return;
    if(l >= x && r <= y){
      appladd(u, k);
      passa(u, l, r);
      return;
    }

    add(2*u, l, (l+r)/2, x, y, k);
    add(2*u+1, (l+r)/2, r, x, y, k);
    v[u].val = v[2*u].val + v[2*u+1].val;
  }

  void set(int u, int l, int r, int x, int y, int k){
    passa(u, l, r);
    if(l >= y || r <= x) return;
    if(l >= x && r <= y){
      applset(u, k);
      passa(u, l, r);
      return;
    }

    set(2*u, l, (l+r)/2, x, y, k);
    set(2*u+1, (l+r)/2, r, x, y, k);
    v[u].val = v[2*u].val + v[2*u+1].val;
  }

  long long get(int u, int l, int r, int x, int y){
    passa(u, l, r);
    if(l >= y || r <= x) return 0LL;
    if(l >= x && r <= y) return v[u].val;
    return get(2*u, l, (l+r)/2, x, y) + get(2*u+1, (l+r)/2, r, x, y);
  }

  void passa(int u, int l, int r){
    if(v[u].toset){
      v[u].val = (long long)(r-l)*v[u].lazyset;
      if(l != r-1) applset(2*u, v[u].lazyset), applset(2*u+1, v[u].lazyset);
    }else{
      v[u].val += (long long)(r-l)*v[u].lazyadd;
      if(l != r-1) appladd(2*u, v[u].lazyadd), appladd(2*u+1, v[u].lazyadd);
    }

    v[u].lazyadd = v[u].lazyset = v[u].toset = 0;
  }
};

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  int n, q; cin >> n >> q;
  vector<int> v(n); for(auto &i : v) cin >> i;

  st st(v);
  while(q--){
    int t; cin >> t;

    if(t == 1){
      int l, r, x; cin >> l >> r >> x;
      st.add(1, 0, n, l-1, r, x);
    }else if(t == 2){
      int l, r, x; cin >> l >> r >> x;
      st.set(1, 0, n, l-1, r, x);
    }else{
      int l, r; cin >> l >> r;
      cout << st.get(1, 0, n, l-1, r) << '\n';
    }
  }
}