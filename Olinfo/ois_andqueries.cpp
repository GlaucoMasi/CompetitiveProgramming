#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int n, q, bit;
vector<array<int, 3>> edges, upds;
vector<long long> ans;

int sz = 1;
vector<vector<array<int, 2>>> v;

long long cost;
vector<int> fat, compsz;
vector<array<int, 4>> buffer;

void init(){
  cost = 0;
  for(auto &i : v) i.clear();
  iota(fat.begin(), fat.end(), 0);
  fill(compsz.begin(), compsz.end(), 1);
}

int get(int i){
  if(fat[i] == i) return i;
  else return get(fat[i]);
}

void join(int a, int b){
  a = get(a), b = get(b);

  if(compsz[a] < compsz[b]) swap(a, b);
  buffer.push_back({a, b, compsz[a], compsz[b]});

  fat[b] = a;
  cost += (long long)compsz[a]*compsz[b]*(1LL<<bit);
  compsz[a] += compsz[b];
}

void rollback(){
  auto [a, b, sa, sb] = buffer.back();
  buffer.pop_back();
  compsz[a] = sa; compsz[b] = sb;
  fat[a] = a; fat[b] = b;
  cost -= (long long)compsz[a]*compsz[b]*(1LL<<bit);
}

void add(int a, int b, int x, int y, int u = 1, int l = 0, int r = sz){
  if(l >= y || r <= x) return;
  if(l >= x && r <= y){
    v[u].push_back({a, b});
    return;
  }

  add(a, b, x, y, 2*u, l, (l+r)/2);
  add(a, b, x, y, 2*u+1, (l+r)/2, r);
}

void dfs(int u = 1, int l = 0, int r = sz){
  for(auto [a, b] : v[u]) join(a, b);

  if(l == r-1) ans[l] += cost;
  else{
    dfs(2*u, l, (l+r)/2);
    dfs(2*u+1, (l+r)/2, r);
  }

  for(auto [a, b] : v[u]) rollback();
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  cin >> n;
  for(int i = 0; i < n-1; i++){
    int a, b, c; cin >> a >> b >> c;
    if(a > b) swap(a, b);
    edges.push_back({a, b, c});
  }

  cin >> q;
  for(int i = 0; i < q; i++){
    int a, b, c; cin >> a >> b >> c;
    if(a > b) swap(a, b);
    upds.push_back({a, b, c});
  }

  while(sz < q+1) sz *= 2;
  v.resize(2*sz);
  fat.resize(n);
  compsz.resize(n);
  ans.resize(sz);

  for(bit = 0; bit < 30; bit++){
    init();
    map<pair<int, int>, int> on;
    
    for(auto [a, b, c] : edges){
      if(c&(1<<bit)) on[{a, b}] = 0;
    }

    for(int t = 0; t < q; t++){
      auto [a, b, c] = upds[t];
      if(c&(1<<bit)){
        if(on.count({a, b})) continue;
        on[{a, b}] = t+1;
      }else{
        if(!on.count({a, b})) continue;
        add(a, b, on[{a, b}], t+1);
        on.erase({a, b});
      }
    }

    for(auto [i, t] : on){
      auto [a, b] = i;
      add(a, b, t, q+1);
    }

    dfs();
  }

  for(int i = 0; i <= q; i++) cout << ans[i] << " ";
}