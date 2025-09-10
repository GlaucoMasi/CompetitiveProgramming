#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

struct st{
  struct node{
    int idx = -1;

    void join(const node &l, const node &r){
      if(r.idx != -1) idx = r.idx;
      else idx = l.idx;
    }
  };

  int sz = 1;
  vector<node> v;
  vector<int> freq;

  st(int n){
    while(sz < n) sz *= 2;
    v.resize(2*sz);
    freq.resize(sz);
  }

  void upd(int u, int k){
    freq[u] += k;
    if(freq[u] == 1) v[u+sz].idx = u;
    if(freq[u] == 0) v[u+sz].idx = -1;
    u += sz;

    while(u > 1){
      u /= 2;
      v[u].join(v[2*u], v[2*u+1]);
    }
  }

  int get(int u, int l, int r, int y){
    if(l >= y) return -1;
    else if(r <= y) return v[u].idx;
    
    int left = get(2*u, l, l+(r-l)/2, y), right = get(2*u+1, l+(r-l)/2, r, y);
    if(right != -1) return right;
    else return left;
  }
};

int main() {
  int n, k; cin >> n >> k;
  vector<pair<int, int>> v(n);
  for(auto &[r, l] : v) cin >> l >> r;
  sort(v.begin(), v.end());

  vector<int> comp;
  for(auto [r, l] : v) comp.push_back(l), comp.push_back(r);
  sort(comp.begin(), comp.end());
  comp.resize(unique(comp.begin(), comp.end())-comp.begin());

  unordered_map<int, int> m; st st(comp.size());
  for(int i = 0; i < comp.size(); i++) m[comp[i]] = i;
  for(auto &[r, l] : v) l = m[l], r = m[r];

  int seen = 0;
  for(auto [r, l] : v){
    int idx = st.get(1, 0, st.sz, l+1);
  
    if(idx == -1){
      if(!k) continue;
      else k--;
    }

    seen++;
    if(idx != -1) st.upd(idx, -1);
    st.upd(r, 1);
  }

  cout << seen;
}