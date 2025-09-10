#include <bits/stdc++.h>
using namespace std;

struct ST{
  int size = 1;
  vector<long long> v;

  void init(int n){
    while(size < n) size *= 2;
    v.resize(2*size);
  }

  void upd(int u, int l, int r, int x, int y, int k){
    if(l >= y || r <= x) return;
    if(l >= x && r <= y) v[u] += k;
    else{
      upd(2*u, l, l + (r-l)/2, x, y, k);
      upd(2*u+1, l + (r-l)/2, r, x, y, k);
    }
  }

  void passa(int u, int l, int r){
    if(!v[u]) return;

    v[2*u] += v[u];
    v[2*u+1] += v[u];
    v[u] = 0;
  }

  long long get(int u, int l, int r, int pos){
    if(l == r-1) return v[u];

    passa(u, l, r);
    int m = l + (r-l)/2;
    if(pos < m) return get(2*u, l, m, pos);
    else return get(2*u+1, m, r, pos);
  }
};

int n, m;
vector<vector<int>> a, b;
vector<vector<pair<int, int>>> edges;
vector<vector<pair<int, int>>> queries;
vector<long long> ans;

vector<int> order, idx, sz;
ST st;

int dfs1(int i){
  order.push_back(i); sz[i] = 1;
  for(auto j : b[i]) sz[i] += dfs1(j);
  return sz[i];
}

void dfs2(int i){
  for(auto [j, l] : edges[i]) st.upd(1, 0, st.size, idx[j], idx[j]+sz[j], l);

  for(auto [j, t] : queries[i]) ans[t] = st.get(1, 0, st.size, idx[j]);

  for(auto j : a[i]) dfs2(j);

  for(auto [j, l] : edges[i]) st.upd(1, 0, st.size, idx[j], idx[j]+sz[j], -l);
}

int main() {
  cin >> n;
  a.resize(n);
  for(int i = 1; i < n; i++){
    int t; cin >> t; t--;
    a[t].push_back(i);
  }

  cin >> m;
  b.resize(m);
  for(int i = 1; i < m; i++){
    int t; cin >> t; t--;
    b[t].push_back(i);
  }
  
  edges.resize(n); queries.resize(n);

  int k; cin >> k;
  for(int i = 0; i < k; i++){
    int a, b, c;
    cin >> a >> b >> c;
    edges[a-1].push_back({b-1, c});
  }

  int q; cin >> q; ans.resize(q);
  for(int i = 0; i < q; i++){
    int a, b;
    cin >> a >> b;
    queries[a-1].push_back({b-1, i});
  }

  st.init(m);
  idx.resize(m); sz.resize(m);
  dfs1(0);
  for(int i = 0; i < m; i++) idx[order[i]] = i;

  dfs2(0);
  for(auto i : ans) cout << i << '\n';
}