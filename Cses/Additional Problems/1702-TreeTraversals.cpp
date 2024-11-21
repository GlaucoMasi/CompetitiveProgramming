#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int n, i = 0;
vector<vector<int>> g;
vector<int> pre, in, idx;

void post(int i){
  for(auto j : g[i]) post(j);
  cout << i+1 << " ";
}

int f(int l, int r){
  if(l > r || idx[pre[i]] < l || idx[pre[i]] > r) return -1;
  int curr = pre[i]; i++;

  int left = f(l, idx[curr]-1);
  if(left != -1) g[curr].push_back(left);

  int right = f(idx[curr]+1, r);
  if(right != -1) g[curr].push_back(right);

  return curr;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  cin >> n;
  pre.resize(n);
  idx.resize(n);
  in.resize(n);
  g.resize(n);

  for(auto &i : pre) cin >> i, i--;
  for(auto &i : in) cin >> i, i--;
  for(int i = 0; i < n; i++) idx[in[i]] = i;

  f(0, n-1);
  post(pre[0]);
}