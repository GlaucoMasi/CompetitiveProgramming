#include <bits/stdc++.h>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

struct st{
  int size = 1;
  vector<int> v;

  void init(vector<int> &data){
    while(size < data.size()) size *= 2;
    v.resize(2*size, 2e9);

    build(1, 0, size, data);
  }

  void build(int u, int l, int r, vector<int> &data){
    if(l == r-1){
      if(l < data.size()) v[u] = data[l];
      
      return;
    }

    build(2*u, l, l + (r-l)/2, data);
    build(2*u+1, l + (r-l)/2, r, data);
    v[u] = min(v[2*u], v[2*u+1]);
  }

  // -1 -> not found
  int get(int u, int l, int r, int x, int y, int k){
    if(l >= y || r <= x) return -1;
    if(l >= x && r <= y){
      if(v[u] > k) return -1;

      if(l == r-1 && v[u] <= k) return l;
    }

    int ans = get(2*u, l, l + (r-l)/2, x, y, k);
    if(ans != -1) return ans;
    else return get(2*u+1, l + (r-l)/2, r, x, y, k);
  }
};

int main() {
  int n; fin >> n;

  vector<int> diff(n+1);
  diff[0] = 0;  

  for(int i = 1; i <= n; i++) fin >> diff[i];

  int a;
  for(int i = 1; i <= n; i++){
    fin >> a;
    diff[i] = a - diff[i] + diff[i-1];
  }

  st st;
  st.init(diff);
  int ans = 0;
  for(int i = 1; i <= n; i++){
    if(diff[i] >= 0) ans = max(ans, i);
    else{
      int idx = st.get(1, 0, st.size, 0, i, diff[i]);
      if(idx != -1) ans = max(ans, i-idx);
    }
  }

  fout << ans;
}