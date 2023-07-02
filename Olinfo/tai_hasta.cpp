#include <bits/stdc++.h>
using namespace std;

int nodes = 2e7;

struct PST{
  struct node{
    int val = 0, vers = 0;
    int left = -1, right = -1;
  };

  int size = 1, idx = 0;
  vector<int> roots;
  vector<node> v;

  void init(int n){ 
    while(size < n) size *= 2;
    v.resize(nodes);
    roots.push_back(build(0, size));
  }

  int get(){ while(idx >= nodes) size++; return idx++; }

  int build(int l, int r){
    int i = get();

    if(l != r-1){
      v[i].left = build(l, l + (r-l)/2);
      v[i].right = build(l + (r-l)/2, r);
    }

    return i;
  }

  void dupe(int vers){
    int i = get();
    v[i] = v[roots.back()];
    v[i].vers = vers;
    roots.push_back(i);
  }

  int upd(int u, int l, int r, int pos, int k, int vers){
    if(v[u].vers != vers){
      int i = get();
      v[i] = v[u]; v[i].vers = vers;
      u = i;
    }

    v[u].val += k;
    
    if(l != r-1){
      int m = l + (r-l)/2;

      if(pos < m) v[u].left = upd(v[u].left, l, m, pos, k, vers);
      else v[u].right = upd(v[u].right, m, r, pos, k, vers);
    }

    return u;
  }

  int get(int u, int l, int r, int x, int y){
    if(l >= y || r <= x) return 0;
    if(l >= x && r <= y) return v[u].val;

    return get(v[u].left, l, l + (r-l)/2, x, y) + get(v[u].right, l + (r-l)/2, r, x, y);
  }
};

PST pst;

int istiga(int l, int r){ return pst.get(pst.roots[r], 0, pst.size, l, pst.size); }

void inizia(int n, int k, int v[], int r[]){
  vector<vector<int>> cl(k);
  pst.init(n);

  for(int i = 0; i < n; i++){
    cl[v[i]].push_back(i);
    if(i != 0) pst.dupe(i);

    if(cl[v[i]].size() >= r[v[i]]) pst.upd(pst.roots.back(), 0, pst.size, cl[v[i]][cl[v[i]].size()-r[v[i]]], r[v[i]], i);

    if(cl[v[i]].size() >= r[v[i]]+1) pst.upd(pst.roots.back(), 0, pst.size, cl[v[i]][cl[v[i]].size()-r[v[i]]-1], -2*r[v[i]], i);

    if(cl[v[i]].size() >= r[v[i]]+2) pst.upd(pst.roots.back(), 0, pst.size, cl[v[i]][cl[v[i]].size()-r[v[i]]-2], r[v[i]], i);
  }
}