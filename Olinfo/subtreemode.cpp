#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> g;
vector<int> ans1, ans2;

unordered_map<int, int> f(int i, vector<int> &z){
  unordered_map<int, int> v;
  v[z[i]] = 1; ans2[i] = z[i];

  for(auto j : g[i]){
    unordered_map<int, int> son = f(j, z);

    if(son.size() > v.size()){
      swap(v, son);
      ans1[i] = ans1[j]; ans2[i] = ans2[j];
    }

    for(auto k : son){
      int t = v[k.first] += k.second; 
      
      if(ans1[i] < t){
        ans1[i] = t;
        ans2[i] = k.first;
      }else if(ans1[i] == t && k.first < ans2[i]) ans2[i] = k.first;
    }
  }
}

vector<int> solve(int n, vector<int> p, vector<int> z){
  g.resize(n); ans1.resize(n, 1); ans2.resize(n);

  for(int i = 1; i < n; i++) g[p[i]].push_back(i);

  f(0, z);

  return ans2;
}