#include <bits/stdc++.h>
using namespace std;

int n, m, k;
vector<int> ans;

int comp;
vector<int> father, sz;

int get(int i){
  if(father[i] != i) return get(father[i]);
  else return i;
}

pair<int, int> join(pair<int, int> edge){
  int a = get(edge.first), b = get(edge.second);

  if(a == b) return {-1, -1};
  comp--;

  if(sz[a] < sz[b]) swap(a, b);
  
  father[b] = a;
  sz[a] += sz[b];
  return {a, b};
}

void disjoin(pair<int, int> edge){
  if(edge.first == -1 && edge.second == -1) return;

  father[edge.second] = edge.second;
  sz[edge.first] -= sz[edge.second];
  comp++;
}

struct st{
  int size = 1;
  vector<vector<pair<int, int>>> v;

  void init(int n){
    while(size < n) size *= 2;
    v.resize(2*size);
  }

  void add(int u, int l, int r, int x, int y, pair<int, int> edge){
    if(l >= y || r <= x) return;
    if(l >= x && r <= y) v[u].push_back(edge);
    else{
      add(2*u, l, l + (r-l)/2, x, y, edge);
      add(2*u+1, l + (r-l)/2, r, x, y, edge);
    }
  }

  void dfs(int u){
    vector<pair<int, int>> rollback;
    for(auto edge : v[u]) rollback.push_back(join(edge));

    if(2*u < v.size()) dfs(2*u), dfs(2*u+1);
    else if(u-size <= k) ans[u-size] = comp;

    for(auto edge : rollback) disjoin(edge);
  }

};

int main() {
  cin >> n >> m >> k;

  vector<pair<pair<int, int>, int>> events;
  ans.resize(k+1);

  comp = n;
  father.resize(n); iota(father.begin(), father.end(), 0);
  sz.resize(n, 1);

  while(m--){
    int a, b; cin >> a >> b; a--; b--;
    if(a > b) swap(a, b);

    events.push_back({{a, b}, 0});
  }

  for(int i = 0; i < k; i++){
    int a, b, c; cin >> c >> a >> b; a--; b--;
    if(a > b) swap(a, b);

    events.push_back({{a, b}, i+1});
  }

  st st;
  st.init(k+2);

  sort(events.begin(), events.end());

  for(int i = 0; i < events.size(); i++){
    auto edge = events[i].first;

    bool closed = 0;
    if(i+1 < events.size() && events[i].first == events[i+1].first) closed = 1;

    st.add(1, 0, st.size, events[i].second, (closed ? events[i+1].second : k+1), edge);

    i += closed;
  }

  st.dfs(1);

  for(auto i : ans) cout << i << " ";
}