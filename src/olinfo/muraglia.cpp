#include <bits/stdc++.h>
using namespace std;

struct st{
  int size = 1;
  vector<int> v, values;

  void init(vector<int> &data){
    while(size < data.size()) size *= 2;
    values = data;
    v.resize(2*size, -2e9);

    build(1, 0, size, data);
  }

  void build(int u, int l, int r, vector<int> &data){
    if(l == r-1){
      if(l < data.size()) v[u] = data[l];
    }else{
      build(2*u, l, l + (r-l)/2, data);
      build(2*u+1, l + (r-l)/2, r, data);

      v[u] = max(v[2*u], v[2*u+1]);
    }
  }

  void update(int i, int k){
    int u = size + i;
    v[u] = k;
    values[i] = k;

    while(u > 1){
      u /= 2;
      v[u] = max(v[2*u], v[2*u+1]);
    }
  }

  int left(int u, int l, int r, int x, int y, int k){
    if(l >= y || r <= x) return -1;
    if(l >= x && r <= y){
      if(v[u] <= k) return -1;
      else if(l == r-1) return l;
    }

    auto temp = left(2*u+1, l + (r-l)/2, r, x, y, k);

    if(temp == -1) return left(2*u, l, l + (r-l)/2, x, y, k);
    else return temp;
  }

  int right(int u, int l, int r, int x, int y, int k){
    if(l >= y || r <= x) return -1;
    if(l >= x && r <= y){
      if(v[u] <= k) return -1;
      else if(l == r-1) return l;
    }

    auto temp = right(2*u, l, l + (r-l)/2, x, y, k);

    if(temp == -1) return right(2*u+1, l + (r-l)/2, r, x, y, k);
    else return temp;
  }

  pair<int, int> query(int i){
    auto l = left(1, 0, size, 0, i, values[i]), r = right(1, 0, size, i+1, size, values[i]);
    return {l == -1 ? 0 : l, r == -1 ? values.size()-1 : r};
  }
};

st st;

void inizializza(int N, vector<int> H){
  st.init(H);
}

void cambia(int x, int h){
  st.update(x, h);
}

pair<int, int> chiedi(int x){
  return st.query(x);
}