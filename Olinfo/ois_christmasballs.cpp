#include <bits/stdc++.h>
using namespace std;

int n, best = 0;
vector<vector<int>> g;
vector<int> v;

vector<pair<int, int>> memo;

unordered_map<int, int> f(int i){
  unordered_map<int, int> ans;
  pair<int, int> freq = {1, 1};
  ans[v[i]] = 1;
  
  if(g[i].size() == 0) return ans;

  for(auto j : g[i]){
    auto t = f(j);

    if(ans.size() < t.size()){
      swap(ans, t);
      freq = memo[j];
    }

    for(auto k : t){
      ans[k.first] += k.second;
      
      if(ans[k.first] == freq.first) freq.second++;
      else if(ans[k.first] > freq.first) freq = {ans[k.first], 1};
    }
  }

  best = max(best, freq.second);
  memo[i] = freq;
  return ans;
}

int main() {
  cin >> n;
  v.resize(n);
  g.resize(n);
  memo.resize(n, {1, 1});

  for(auto &i : v) cin >> i;

  int a;
  for(int i = 1; i < n; i++){
    cin >> a;
    g[a].push_back(i);
  }

  f(0);
  cout << best;
}