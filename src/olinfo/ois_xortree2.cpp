#include <bits/stdc++.h>
using namespace std;

vector<int> prefxor;
vector<vector<pair<int, int>>> g;

void f(int i, int p){
  for(auto j : g[i]){
    if(j.first == p) continue;
    prefxor[j.first] = prefxor[i]^j.second;
    f(j.first, i);
  }
}

struct node{
  int num = 0, l = -1, r = -1;
};

int sz = 32, idx = 1;
vector<node> trie(2e6);

void upd(int v, int k){
  int curr = 0; trie[0].num += k;
  for(int i = sz-1; i >= 0; i--){
    if(v & (1<<i)){
      if(trie[curr].r == -1) trie[curr].r = idx++;
      curr = trie[curr].r;
    }else{
      if(trie[curr].l == -1) trie[curr].l = idx++;
      curr = trie[curr].l;      
    }

    trie[curr].num += k;
  }  
}

int calc(int v){
  int ans = 0, curr = 0;
  for(int i = sz-1; i >= 0; i--){
    if(v & (1<<i)){
      if(trie[curr].l != -1 && trie[trie[curr].l].num){
        ans += (1<<i);
        curr = trie[curr].l;
      }else curr = trie[curr].r;
    }else{
      if(trie[curr].r != -1 && trie[trie[curr].r].num){
        ans += (1<<i);
        curr = trie[curr].r;
      }else curr = trie[curr].l;
    }    
  }

  return ans;
}

vector<int> ans;

struct st{
  int sz = 1;
  vector<vector<int>> add;

  st(int n){
    while(sz < n) sz *= 2;
    add.resize(2*sz);
  }

  void range(int u, int l, int r, int x, int y, int v){
    if(l >= y || r <= x) return;
    if(l >= x && r <= y){
      add[u].push_back(v);
      return;
    }

    range(2*u, l, (l+r)/2, x, y, v);
    range(2*u+1, (l+r)/2, r, x, y, v);
  }

  void dfs(int u, int val){
    for(auto i : add[u]){
      upd(i, 1);
      val = max(val, calc(i));
    }

    if(2*u < add.size()){
      dfs(2*u, val);
      dfs(2*u+1, val);
    }else if(u-sz < ans.size()) ans[u-sz] = val;

    for(auto i : add[u]) upd(i, -1);
  }
};

int main() {
  int n, q; cin >> n >> q;

  g.resize(n); prefxor.resize(n);
  for(int i = 0; i < n-1; i++){
    int a, b, c; cin >> a >> b >> c;
    g[--a].push_back({--b, c});
    g[b].push_back({a, c});
  }

  f(0, -1);

  vector<pair<int, int>> quer;
  for(int i = 0; i < q; i++){
    int a; cin >> a;
    quer.push_back({--a, i});
  }
  sort(quer.begin(), quer.end());

  st st(q+1);

  for(int i = 0; i < q; i++){
    if(i != q-1 && quer[i].first == quer[i+1].first){
      st.range(1, 0, st.sz, quer[i].second, quer[i+1].second, prefxor[quer[i].first]);
      i++;
    }else st.range(1, 0, st.sz, quer[i].second, q, prefxor[quer[i].first]);
  }

  ans.resize(q);
  st.dfs(1, 0);
  for(auto i : ans) cout << i << '\n';
}