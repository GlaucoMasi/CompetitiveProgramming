#include <bits/stdc++.h>
using namespace std;

int n, ind = -1;
vector<vector<pair<int, int>>> v;
vector<pair<pair<int, int>, int>> lista;
vector<int> comp;
vector<long long> memo;
map<int, int> m;

long long f(int i){
  if(i == ind+3) return 0;
  if(memo[i] != -1) return memo[i];
  
  long long best = 0;
  for(auto j : v[i]){
    best = max(best, f(j.first+1) + j.second);
  }
  
  best = max(best, f(i+1));

  return memo[i] = best;
}

int main() {
  cin >> n;

  int a, b, c;
  for(int i = 0; i < n; i++){
    cin >> a >> b >> c;
    lista.push_back({{a, b}, c});
    comp.push_back(a);
    comp.push_back(b);
  }

  sort(comp.begin(), comp.end());
  int last = -1;
  for(auto i : comp){
    if(i != last){
      ind++;
      m[i] = ind;
    }

    last = i;
  }

  v.resize(ind+5);
  memo.resize(ind+5, -1);
  for(auto i : lista){
    v[m[i.first.first]].push_back({m[i.first.second], i.second});
  }

  cout << f(0);
}