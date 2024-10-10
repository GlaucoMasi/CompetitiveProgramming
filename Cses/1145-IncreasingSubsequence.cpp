#include <bits/stdc++.h>
using namespace std;

struct ST{
  struct Node{
    int val = 0;

    void join(const Node &r, const Node &l){
      val = max(r.val, l.val);
    }
  };

  int size = 1;
  vector<Node> v;

  void init(int n){
    while(size < n) size *= 2;
    v.resize(2*size, Node());
  }
  
  void update(int u, int val){
    int pos = size + u;
    v[pos].val = val;
    
    while(pos > 1){
      pos /= 2;
      v[pos].join(v[2*pos], v[2*pos+1]);
    }
  }

  int q(int u, int l, int r, int x, int y){
    if(l >= y || r <= x) return 0;
    if(l >= x && r <= y) return v[u].val;

    return max(
      q(2*u, l, l + (r-l)/2, x, y),
      q(2*u+1, l + (r-l)/2, r, x, y)
    );
  }

  int q(int a){ return q(1, 0, size, 0, a); }

  void stampa() {
    for(auto i : v) cout << i.val << endl;
  }
};

int main() {
  int n; cin >> n;
  vector<pair<int, int>> v(n);
  for(int i = 0; i < n; i++){
    cin >> v[i].first;
    v[i].second = -i;
  }

  ST st;
  st.init(n);

  sort(v.begin(), v.end());
  for(auto i : v){
    int a = st.q(-i.second);
    st.update(-i.second, a+1);
  }

  cout << st.q(n);
}