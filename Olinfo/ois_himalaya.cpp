#include <bits/stdc++.h>
using namespace std;

struct st{
  int size = 1;
  vector<long long> v;

  st(vector<long long> &data){
    while(size < data.size()) size *= 2;
    v.resize(2*size, 1e18);
    build(1, 0, size, data);
  }

  void build(int u, int l, int r, vector<long long> &data){
    if(l == r-1){
      if(l < data.size()) v[u] = data[l];
      return;
    }

    build(2*u, l, l + (r-l)/2, data);
    build(2*u+1, l + (r-l)/2, r, data);
    v[u] = min(v[2*u], v[2*u+1]);
  }

  int get(int u, int l, int r, int x, int y, long long k){
    if(l >= y || r <= x) return -1;
    if(l == r-1){
      if(v[u] <= k) return l;
      else return -1;
    }

    if(v[2*u] > k) return get(2*u+1, l + (r-l)/2, r, x, y, k);
    
    auto temp = get(2*u, l, l + (r-l)/2, x, y, k);
    if(temp == -1) return get(2*u+1, l + (r-l)/2, r, x, y, k);
    else return temp;
  }

  int query(int a, long long b){ return get(1, 0, size, a+1, size, b); }
};

int main() {
  int n, v; long long k;
  cin >> n >> k >> v;

  vector<long long> h(n); 
  cin >> h[0]; h[0] *= 10*k;
  long long last = h[0];
  for(int i = 1; i < n; i++){
    cin >> h[i];
    h[i] *= 10*k;
    long long temp = h[i-1] - h[i] + last;
    last = h[i];
    h[i] = temp;
  }

  st st(h);
  for(int i = 0; i < n; i++){
    auto ans = st.query(i, h[i]-k*v*v/2);
    cout << (ans == -1 ? n-1 : ans-1) << " ";
  }
}