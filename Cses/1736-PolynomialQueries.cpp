#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

struct st{
  struct node{
    long long val = 0, lazyadd = 0, lazycount = 0;
  };

  int sz = 1;
  vector<node> v;

  st(vector<int> &data){
    while(sz < data.size()) sz *= 2;
    v.resize(2*sz);
    build(1, 0, sz, data);
  }

  void build(int u, int l, int r, vector<int> &data){
    if(l == r-1){
      if(l < data.size()) v[u].val = data[l];
    }else{
      build(2*u, l, (l+r)/2, data);
      build(2*u+1, (l+r)/2, r, data);
      v[u].val = v[2*u].val+v[2*u+1].val;
    }
  }

  void passa(int u, int l, int r){
    v[u].val += (long long)(r-l)*v[u].lazyadd;
    v[u].val += (long long)(r-l)*(r-l+1)*v[u].lazycount/2LL;

    if(l != r-1){
      v[2*u].lazyadd += v[u].lazyadd;
      v[2*u+1].lazyadd += v[u].lazyadd;

      v[2*u].lazycount += v[u].lazycount;
      v[2*u+1].lazycount += v[u].lazycount;
      v[2*u+1].lazyadd += (long long)((l+r)/2-l)*v[u].lazycount;
    }

    v[u].lazyadd = v[u].lazycount = 0;
  }

  void upd(int u, int l, int r, int x, int y){
    passa(u, l, r);
    if(l >= y || r <= x) return;
    if(l >= x && r <= y){
      v[u].lazycount++;
      v[u].lazyadd += (long long)(l-x);
      passa(u, l, r);
      return;
    }

    upd(2*u, l, (l+r)/2, x, y);
    upd(2*u+1, (l+r)/2, r, x, y);
    v[u].val = v[2*u].val+v[2*u+1].val;
  }

  long long get(int u, int l, int r, int x, int y){
    passa(u, l, r);
    if(l >= y || r <= x) return 0LL;
    if(l >= x && r <= y) return v[u].val;
    return get(2*u, l, (l+r)/2, x, y) + get(2*u+1, (l+r)/2, r, x, y);
  }
};

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  int n, q; cin >> n >> q;
  vector<int> v(n); for(auto &i : v) cin >> i;

  st st(v);
  while(q--){
    int t, a, b; cin >> t >> a >> b; a--;
    if(t == 1) st.upd(1, 0, st.sz, a, b);
    else cout << st.get(1, 0, st.sz, a, b) << '\n';
    //for(int k = 1; k < 30; k++) fout << k << " " << st.v[k].val << " " << st.v[k].lazyadd << " " << st.v[k].lazycount << '\n';
    //fout << '\n';
  }
}