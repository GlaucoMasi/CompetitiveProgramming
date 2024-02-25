#include <bits/stdc++.h>
using namespace std;

struct pst{
  struct node{
    int sz = 0, val;
    int l, r;
  };

  int sz = 1, idx = 0;
  vector<node> v;
  vector<int> roots;

  pst(int n){
    while(sz < n) sz *= 2;
    v.resize(2e7);
    roots.push_back(build(0, sz));
  }

  int build(int l, int r){
    int u = idx++;
    
    if(l != r-1){
      v[u].l = build(l, (l+r)/2);
      v[u].r = build((l+r)/2, r);
    }

    return u;
  }

  int upd(int u, int l, int r, int m){
    if(m < l || m >= r) return u;

    v[idx] = v[u];
    u = idx++;
    v[u].sz++;
  
    if(l != r-1){
      v[u].l = upd(v[u].l, l, (l+r)/2, m);
      v[u].r = upd(v[u].r, (l+r)/2, r, m);
    }

    return u;
  }

  int query(int i, int j, int l, int r, int k){
    if(l == r-1) return l;

    int tot = v[v[j].l].sz - v[v[i].l].sz;
    if(tot >= k) return query(v[i].l, v[j].l, l, (l+r)/2, k);
    else return query(v[i].r, v[j].r, (l+r)/2, r, k-tot);
  }
};

int main() {
  int n, m; cin >> n >> m;
  vector<int> v(n), comp;

  for(int i = 0; i < n; i++){
    cin >> v[i];
    comp.push_back(v[i]);
  }

  map<int, int> mapping;
  sort(comp.begin(), comp.end());
  comp.resize(unique(comp.begin(), comp.end())-comp.begin());
  for(int i = 0; i < comp.size(); i++) mapping[comp[i]] = i;

  pst pst(comp.size());
  for(auto &i : v) pst.roots.push_back(pst.upd(pst.roots.back(), 0, pst.sz, mapping[i]));

  while(m--){
    int l, r, k; cin >> l >> r >> k;
    cout << comp[pst.query(pst.roots[l-1], pst.roots[r], 0, pst.sz, k)] << '\n';
  }
}