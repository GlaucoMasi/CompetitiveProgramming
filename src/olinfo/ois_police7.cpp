#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

struct st{
  struct node{
    long long max = 0, sum = 0;
  
    void join(const node &l, const node &r, const long long u){
      if(r.max >= l.max){
        max = r.max;
        sum = r.sum;
      }else{
        max = l.max;
        sum = r.sum+u;
      }
    }
  };

  vector<node> v;
  int size = 1;

  st(vector<int> &data){
    while(size < data.size()) size *= 2;
    v.resize(2*size); data.resize(size);
    build(1, 0, size, data);
  }

  long long calc(int u){ return get(2*u, v[2*u+1].max); }

  long long get(int u, long long right){
    if(2*u >= v.size()){
      if(v[u].max > right) return v[u].max;
      else return 0;
    }

    if(v[2*u].max != v[u].max) return get(2*u+1, right);
    else if(v[2*u+1].max <= right) return get(2*u, right);
    else return v[u].sum - v[2*u+1].sum + get(2*u+1, right);
  }

  void build(int u, int l, int r, vector<int> &data){
    if(l == r-1) v[u].max = v[u].sum = data[l];
    else{
      build(2*u, l, l + (r-l)/2, data);
      build(2*u+1, l + (r-l)/2, r, data);
      v[u].join(v[2*u], v[2*u+1], calc(u));
    }
  }

  void upd(int pos, int k){
    int u = size + pos;
    v[u].max = v[u].sum = k;

    while(u > 1){
      u /= 2;
      v[u].join(v[2*u], v[2*u+1], calc(u));
    }
  }
};

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n, q; cin >> n >> q;
  vector<int> v(n); for(auto &i : v) cin >> i;
  st st(v);

  int a, b;
  while(q--){
    cin >> a >> b;
    st.upd(a, b);

    cout << st.v[1].sum << endl;
  }
}