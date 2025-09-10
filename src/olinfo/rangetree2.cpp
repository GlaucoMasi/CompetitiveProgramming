#include <bits/stdc++.h>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

struct ST{
  struct Node{
    int one = 0, two = 0, three = 0;
    int lazy = 0;

    void join(const Node &l, const Node &r){
      one = l.one + r.one;
      two = l.two + r.two;
      three = l.three + r.three;
    }
  };

  int n, size = 1;
  vector<Node> v;

  void init(int t){
    n = t;
    while(size < n) size *= 2;

    v.resize(2*size, Node());
    build(1, 0, size);
  }

  void build(int u, int l, int r){
    if(l < n && r <= n){
      v[u].three = r - l;

      if(l == r-1) return;

      build(2*u, l, l + (r-l)/2);
      build(2*u+1, l + (r-l)/2, r);
      return;
    }else if(l >= n) return;

    v[u].three = n - l;
    build(2*u, l, l + (r-l)/2);
    build(2*u+1, l + (r-l)/2, r);
  }

  void passa(int u, int l, int r){
    if(!v[u].lazy) return;

    int temp = v[u].lazy % 3;
    v[u].lazy = 0;

    if(l != r-1){
      v[2*u].lazy += temp;
      v[2*u+1].lazy += temp;
    }

    while(temp--){
      int t = v[u].one;
      v[u].one = v[u].two;
      v[u].two = v[u].three;
      v[u].three = t;
    }
  }

  void update(int u, int l, int r, int x, int y){
    if(l >= y || r <= x) return;
    if(l >= x && r <= y){
      v[u].lazy++;
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

    if(l >= x && r <= y) return v[u].three;

    return get(2*u, l, l + (r-l)/2, x, y) + get(2*u+1, l + (r-l)/2, r, x, y);
  }

  int smista(int c, int l, int r){
    if(!c){
      update(1, 0, size, l, r);
      return 0;
    }else return get(1, 0, size, l, r);
  }
};

int main() {
  int n, q;
  fin >> n >> q;

  ST st;
  st.init(n);

  while(q--){
    int a, b, c;
    fin >> c >> a >> b;
    int temp = st.smista(c, a, b+1);
    if(c) fout << temp << endl;
  }
}