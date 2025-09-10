#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int n, m, q, comps;
vector<int> fat, sz;

int get(int i){
  if(fat[i] == i) return i;
  return fat[i] = get(fat[i]);
}

void join(int a, int b){
  a = get(a), b = get(b);

  if(a == b) return;
  
  comps--;
  if(sz[a] < sz[b]) swap(a, b);
  fat[b] = a;
  sz[a] += sz[b];
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  cin >> n >> m >> q;

  comps = n;
  fat.resize(n);
  sz.resize(n, 1);
  iota(fat.begin(), fat.end(), 0);

  set<pair<int, int>> s;
  vector<pair<int, int>> edg(m);
  for(auto &[a, b] : edg){
    cin >> a >> b;
    a--; b--;
    if(a > b) swap(a, b);
  }

  vector<pair<int, int>> down(q);
  for(auto &[a, b] : down){
    cin >> a >> b;
    a--; b--;
    if(a > b) swap(a, b);
    s.insert({a, b});
  }

  for(auto [a, b] : edg) if(!s.count({a, b})) join(a, b);

  vector<int> ans(q);
  for(int i = q-1; i >= 0; i--){
    ans[i] = comps;
    auto [a, b] = down[i];
    join(a, b);
  }

  for(auto i : ans) cout << i << " ";
}