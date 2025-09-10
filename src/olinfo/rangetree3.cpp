#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

struct ST{
  struct Node{
    long long sum, pref, suff, best;

    Node() {
      sum = pref = suff = best = 0;
    }
  
    void join(const Node &l, const Node &r){
      pref = max(l.pref, l.sum + r.pref);
      suff = max(r.suff, r.sum + l.suff);
      sum = l.sum + r.sum;

      best = max(max(max(pref, suff), l.suff+r.pref), max(l.best, r.best));
    }

    void upd(int k){
      sum = pref = suff = best = k;
    }
  };

  int size = 1;
  vector<Node> v;
  ST(vector<int> &data){
    while(size < data.size()) size *= 2;
    v.resize(2*size, Node());

    build(1, 0, size, data);
  }

  void build(int u, int l, int r, vector<int> &data){
    if(l == r-1){
      if(l < data.size()) v[u].upd(data[l]);
    }else{
      build(2*u, l, l + (r-l)/2, data);
      build(2*u+1, l + (r-l)/2, r, data);
      v[u].join(v[2*u], v[2*u+1]);
    }
  }

  void update(int pos, int k){
    int u = size + pos;
    v[u].upd(k);

    while(u > 1){
      u /= 2;
      v[u].join(v[2*u], v[2*u+1]);
    }
  }

  long long get(int u, int l, int r, int x, int y){
    if(l >= y || r <= x) return -1e9;
    if(l >= x && r <= y) return v[u].best;

    return max(
        max(
          max(prefix(u, l, r, x, y), suffix(u, l, r, x, y)), 
          max(get(2*u, l, l + (r-l)/2, x, y), get(2*u+1, l + (r-l)/2, r, x, y))), 
        prefix(2*u+1, l + (r-l)/2, r, x, y) + suffix(2*u, l, l + (r-l)/2, x, y)
      );
  }

  long long somma(int u, int l, int r, int x, int y){
    if(l >= y || r <= x) return -1e9;
    if(l >= x && r <= y) return v[u].sum;

    return somma(2*u, l, l + (r-l)/2, x, y) + somma(2*u+1, l + (r-l)/2, r, x, y);
  }

  long long prefix(int u, int l, int r, int x, int y){
    if(l >= y || r <= x) return -1e9;
    if(l >= x && r <= y) return v[u].pref;

    return max(
      prefix(2*u, l, l + (r-l)/2, x, y), 
      somma(2*u, l, l + (r-l)/2, x, y) + prefix(2*u+1, l + (r-l)/2, r, x, y)
    );
  }

  long long suffix(int u, int l, int r, int x, int y){
    if(l >= y || r <= x) return -1e9;
    if(l >= x && r <= y) return v[u].suff;

    return max(
      suffix(2*u+1, l + (r-l)/2, r, x, y), 
      somma(2*u+1, l + (r-l)/2, r, x, y) + suffix(2*u, l, l + (r-l)/2, x, y)
    );
  }
};

int main() {
  int n; fin >> n;
  vector<int> v(n);
  for(auto &i : v) fin >> i;

  ST st(v);
  int m; fin >> m;
  int a, b, c;
  while(m--){
    fin >> a >> b >> c;

    if(!a) st.update(b-1, c);
    else fout << st.get(1, 0, st.size, b-1, c) << endl;
  }
}