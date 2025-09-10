#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<set<int>> g;
vector<pair<int, int>> ans;
vector<int> num;
set<pair<int, int>> edges;

int tot = 0;

void add(int a, int b){
  if(a > b) swap(a, b);

  edges.insert({a, b});
  g[a].insert(b); g[b].insert(a);
}

void remove(int a, int b){
  if(a > b) swap(a, b);

  edges.erase({a, b});
  g[a].erase(b); g[b].erase(a);
}

bool f(){
  if(!tot){
    for(auto [a, b] : ans) cout << a << " " << b << '\n';
    return 1;
  }

  if(edges.size() < tot) return 0;

  for(int i = 0; i < n; i++){
    if(num[i] == g[i].size() && num[i]){
      int j = *g[i].begin();
      remove(i, j);
      num[i]--; num[j]--;
      tot--;
      ans.push_back({i, j});

      bool t = f();

      add(i, j);
      num[i]++; num[j]++;
      tot++;
      ans.pop_back();

      return t;
    }
  }

  auto [a, b] = *edges.begin();
  for(auto [c, d] : edges){
    if(num[c]-g[c].size() + num[d]-g[d].size() < num[a]-g[a].size() + num[b]-g[b].size()) a = c, b = d;
  }

  remove(a, b);
  num[a]--; num[b]--;
  tot--;
  ans.push_back({a, b});

  if(f()) return 1;

  num[a]++; num[b]++;
  tot++;
  ans.pop_back();

  bool t = f();
  add(a, b);
  return t;
}

int main() {
  cin >> n >> m;
  g.resize(n);
  num.resize(n);

  for(auto &i : num){
    cin >> i;
    tot += i;
  }

  tot /= 2;

  for(int i = 0; i < m; i++){
    int a, b; cin >> a >> b;
    add(a, b);
  }

  f();
}