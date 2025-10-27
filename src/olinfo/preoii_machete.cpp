#include <bits/stdc++.h>
using namespace std;

int ans = 0;
vector<vector<int>> g;

int f(int i, int k){
  int depth = 1;
  for(auto j : g[i]){
    int child = f(j, k)+1;

    if(i && child%k == 0){
      ans++;
      child = 1;
    }

    depth = max(depth, child);
  }
  
  return depth;
}

int machete(int n, int k, vector<int> p) {
  g.resize(n);
  for(int i = 1; i < n; i++) g[p[i]].push_back(i);
  f(0, k);
  return ans;
}

#ifndef EVAL
int main() {
  int N, K;
  cin >> N >> K;
  vector<int> P(N);
  for(auto &i : P) cin >> i;

  cout << machete(N, K, P) << endl;
}   
#endif