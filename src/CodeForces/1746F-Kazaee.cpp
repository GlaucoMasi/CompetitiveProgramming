#include <bits/stdc++.h>
using namespace std;
 
const int tot = 25;
 
struct st{
  int size = 1;
  vector<int> v;
 
  void init(vector<int> &data){
    while(size < data.size()) size *= 2;
    v.resize(2*size);
    data.resize(size);
    build(1, 0, size, data);
  }
 
  void build(int u, int l, int r, vector<int> &data){
    if(l == r-1){
      v[u] = data[l];
    }else{
      build(2*u, l, l + (r-l)/2, data);
      build(2*u+1, l + (r-l)/2, r, data);
 
      v[u] = v[2*u]+v[2*u+1];
    }
  }
 
  void upd(int pos, int k){
    int u = size+pos;
    v[u] = k;
 
    while(u > 1){
      u /= 2;
      v[u] = v[2*u]+v[2*u+1];
    }
  }
 
  int query(int u, int l, int r, int x, int y){
    if(l >= y || r <= x) return 0;
    if(l >= x && r <= y) return v[u];

    return query(2*u, l, l + (r-l)/2, x, y) + query(2*u+1, l + (r-l)/2, r, x, y);
  }
};

mt19937 rnd;
map<int, int> memo;
array<int, tot> t;
 
int get(int a){
  if(!memo.count(a)) memo[a] = rnd();
  return memo[a];
}
 
int main() {
  ios::sync_with_stdio(false); cin.tie(NULL), cout.tie(NULL);
  int n, q; cin >> n >> q;

  array<st, tot> st;

  vector<int> v(n);
  for(int i = 0; i < n; i++){
    int a; cin >> a;
    v[i] = get(a);
  }

  vector<int> data(n);
  for(int j = 0; j < tot; j++){
    for(int i = 0; i < n; i++) data[i] = (bool)(v[i]&(1<<j));
    st[j].init(data);
  }
  
  while(q--){
    int c; cin >> c;
 
    if(c == 1){
      int a, b; cin >> a >> b;
      int s = get(b);
      for(int i = 0; i < tot; i++) st[i].upd(a-1, (bool)(s&(1<<i)));
    }else{
      int l, r, k; cin >> l >> r >> k;
 
      bool ans = 1;
      for(int i = 0; i < tot; i++){
        if(st[i].query(1, 0, st[i].size, l-1, r)%k){
          ans = 0;
          break;
        }
      }
      
      if(ans) cout << "YES\n";
      else cout << "NO\n";
    }
  }
}