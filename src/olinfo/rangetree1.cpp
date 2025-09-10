#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

struct ST{
  struct Node{
    int val = 0;
    bool lazy = 0;

    void join(const Node &r, const Node &l){
      val = r.val + l.val;
    }
  };

  int n, size = 1;
  vector<Node> v;

  void init(int t){
    n = t;
    while(size < n) size *= 2;

    v.resize(2*size, Node());
  } 

  void passa(int u, int l, int r){
    if(!v[u].lazy) return;
    v[u].lazy = 0;

    v[u].val = r-l - v[u].val;
    if(l != r-1){
      v[2*u].lazy = !v[2*u].lazy;
      v[2*u+1].lazy = !v[2*u+1].lazy;
    }
  }

  void update(int u, int l, int r, int x, int y){
    if(l >= y || r <= x) return;
    if(l >= x && r <= y){
      v[u].lazy = !v[u].lazy;
      if(v[u].lazy) passa(u, l, r);
      return;
    }

    update(2*u, l, l + (r-l)/2, x, y);
    update(2*u+1, l + (r-l)/2, r, x, y);

    passa(2*u, l, l + (r-l)/2);
    passa(2*u+1, l + (r-l)/2, r);
    v[u].join(v[2*u], v[2*u+1]);
  }

  int get(int u, int l, int r, int x, int y){
    if(l >= y || r <= x) return 0;
    
    if(v[u].lazy) passa(u, l, r);
    
    if(l >= x && r <= y) return v[u].val;
  
    return get(2*u, l, l + (r-l)/2, x, y) + get(2*u+1, l + (r-l)/2, r, x, y);
  }

  int smista(int c, int l, int r){
    if(c == 0){ 
      update(1, 0, size, l, r);
      return 0;
    }else return get(1, 0, size, l, r);
  }

  void stampa() {
    for(auto i : v) fout << i.val << " " << i.lazy << endl;
    fout << endl << endl;
  }
};

int main() {
  int n, q;
  fin >> n >> q;
  ST st; st.init(n); 

  while(q--){
    int a, b, c;
    fin >> a >> b >> c;
    int temp = st.smista(a, b, c+1);
    if(a) fout << temp << endl;
  }
}