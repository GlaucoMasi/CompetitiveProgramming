#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

struct node{
  int l, r;
  int num = 0;
  long long val = 1;
};

int mod = 1e9+7;
const int nodes = 5e6;
static node v[nodes];
vector<int> roots;

struct pst{
  int sz = 1, idx = 0;

  pst(int n){
    while(sz < n) sz *= 2;
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

  int upd(int u, int l, int r, int i, long long val){
    if(l > i || r <= i) return u;
    
    v[idx] = v[u];
    u = idx++;
    
    if(l == r-1){
      v[u].val = (v[u].val*val);
      v[u].num++;
    }else{
      v[u].l = upd(v[u].l, l, (l+r)/2, i, val);
      v[u].r = upd(v[u].r, (l+r)/2, r, i, val);
      v[u].val = (v[v[u].l].val*v[v[u].r].val)%mod;
      v[u].num = v[v[u].l].num+v[v[u].r].num;
    }

    return u;
  }

  pair<long long, long long> query(int l, int r, int k){
    if(v[r].num-v[l].num == k) return {v[r].val, v[l].val};

    int left = v[v[r].r].num-v[v[l].r].num;
    if(left >= k) return query(v[l].r, v[r].r, k);
    else{
      auto t = query(v[l].l, v[r].l, k-left);
      t.first = (t.first*v[v[r].r].val)%mod;
      t.second = (t.second*v[v[l].r].val)%mod;
      return t;
    }
  }
};

long long exp(long long a, int b){
  if(b == 0) return 1;
  if(b == 1) return a;
  
  long long ans = exp(a, b/2);
  ans = (ans*ans)%mod;
  if(b%2) ans = (ans*a)%mod;
  return ans;
}

int main() {
  int n, q; cin >> n >> q;
  vector<pair<int, int>> v(n), comp(n);
  for(int i = 0; i < n; i++){
    cin >> v[i].first;
    comp[i] = {v[i].first, i};
  }

  sort(comp.begin(), comp.end());
  for(int i = 0; i < comp.size(); i++) v[comp[i].second].second = i;

  pst pst(n);
  for(int i = 0; i < n; i++) roots.push_back(pst.upd(roots.back(), 0, pst.sz, v[i].second, v[i].first));

  while(q--){
    int l, r, k; cin >> l >> r >> k;
    auto t = pst.query(roots[l], roots[r+1], k);
    cout << (t.first * exp(t.second, mod-2))%mod << '\n';
  }
}