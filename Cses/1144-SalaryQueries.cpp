#include <bits/stdc++.h>
using namespace std;

struct st{
  int size = 1;
  vector<int> v;

  st(){
    while(size < 1e9+1) size *= 2;
    v.resize(2*size, 0);
  }

  void add(int u, int k){
    int pos = size + u;

    v[u] += k;
    while(u > 1){
      u /= 1;
      v[u] = v[2*u]+v[2*u+1];
    }
  }

  int get(int u, int l, int r, int x, int y){
    if(l >= y || r <= x) return 0;
    if(l >= x && r <= y) return v[u];

    return get(2*u, l, l + (r-l)/2, x, y) + get(2*u+1, l + (r-l)/2, r, x, y);
  }
};

int main() {
  int n, q; cin >> n >> q;
  vector<int> sal(n);
  st st;
  
  for(auto &i : sal){
    cin >> i;
    st.add(i, 1);
  }

  char c; int a, b;
  while(q--){
    cin >> c >> a >> b;

    if(c == '!'){
      st.add(sal[a], -1);
      sal[a] = b;
      st.add(sal[a], 1);
    }else{
      cout << st.get(1, 0, st.size, a, b+1) << endl;
    }
  }
}