#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> p, col, idx, sz;

void f(int i, int j, int d){
  if(col[i] != -1) return;
  col[i] = j; idx[i] = d; sz[j] = d+1;
  f(p[i], j, d+1);
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
  cin >> n;
  p.resize(n);
  for(auto &i : p) cin >> i;

  col.resize(n, -1);
  idx.resize(n);
  sz.resize(n);
  for(int i = 0; i < n; i++) f(i, i, 0);

  int q; cin >> q;
  while(q--){
    int a, b; cin >> a >> b;
    if(col[a] != col[b]) cout << "-1 ";
    else{
      if(idx[a] > idx[b]) swap(a, b);
      cout << min(idx[b]-idx[a], sz[col[a]]-idx[b]+idx[a]) << " ";
    }
  }
}