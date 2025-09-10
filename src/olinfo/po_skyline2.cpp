#include <bits/stdc++.h>
using namespace std;

struct ST{
  struct node{
    long long sum = 0;
    int max = -1;

    void join(const node &l, const node &r){
      sum = l.sum+r.sum;
      max = std::max(l.max, r.max);
    }
  };

  int size = 1;
  vector<node> v;

  void init(vector<int> &data){
    while(size < data.size()) size *= 2;
    v.resize(2*size); data.resize(size);
    build(1, 0, size, data);
  }

  void build(int u, int l, int r, vector<int> &data){
    if(l == r-1) v[u].sum = v[u].max = data[l];
    else{
      build(2*u, l, l + (r-l)/2, data);
      build(2*u+1, l + (r-l)/2, r, data);
      v[u].join(v[2*u], v[2*u+1]);
    }
  }

  void upd(int u, int k){
    u += size;
    v[u].sum = v[u].max = k;

    while(u > 1){
      u /= 2;
      v[u].join(v[2*u], v[2*u+1]);
    }
  }
};

int m;
ST st;

void Inizializza(int N, int M, int* H){  
  vector<int> data;
  for(int i = 0; i < N; i++) data.push_back(H[i]);
  st.init(data);
  m = M;
}

int Cambia(int P, int V){
  st.upd(P, V);
  return (!(st.v[1].sum % m) && st.v[1].max <= st.v[1].sum/m);
}