#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int n;
vector<int> v;

struct ST{
  int size = 1;
  vector<int> v;

  void init(){
    while(size < n) size *= 2;
    v.resize(2*size, 1e9);
  }

  void update(int pos, int k){
    int u = size + pos;
    v[u] = k;

    while(u > 1){
      u /= 2;
      v[u] = min(v[2*u], v[2*u+1]);
    }
  }

  int getmin(int u, int l, int r, int x, int y){
    if(l >= y || r <= x) return 1e9;
    if(l >= x && r <= y) return v[u];

    return min(
      getmin(2*u, l, l + (r-l)/2, x, y),
      getmin(2*u+1, l + (r-l)/2, r, x, y)
    );
  }
};

int main() {
  fin >> n; n++;

  v.resize(n);
  for(auto &i : v) fin >> i;
  
  ST st;
  st.init();
  st.update(n-1, 0);
  for(int i = n-2; i >= 0; i--) st.update(i, st.getmin(1, 0, st.size, i+1, min(i+v[i]+1, n))+1);
  fout << st.v[st.size];
}