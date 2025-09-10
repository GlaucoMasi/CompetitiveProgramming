#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

struct st{
  int size = 1;
  vector<int> v;

  st(int n){
    while(size < n) size *= 2;
    v.resize(2*size);
  }

  int get(int u, int l, int r, int x, int y){
    if(l >= y || r <= x) return 0;
    if(l >= x && r <= y) return v[u];

    return max(
      get(2*u, l, l + (r-l)/2, x, y),
      get(2*u+1, l + (r-l)/2, r, x, y)
    );
  }

  void upd(int u, int k){
    u += size;
    v[u] = max(v[u], k);

    while(u > 1){
      u /= 2;
      v[u] = max(v[2*u], v[2*u+1]);
    }
  }
};

int main() {
  int m, f, c;
  fin >> m >> f >> c;

  st st(f);

  vector<vector<int>> cott(m);
  for(int i = 0; i < c; i++){
    int a, b; fin >> a >> b;
    cott[a-1].push_back(b-1);
  }

  for(int i = 0; i < m; i++){
    vector<int> ans(cott[i].size());
    for(int j = 0; j < cott[i].size(); j++) ans[j] = st.get(1, 0, st.size, 0, cott[i][j]);
    for(int j = 0; j < cott[i].size(); j++) st.upd(cott[i][j], ans[j]+1);
  }

  fout << 2*st.v[1];
}