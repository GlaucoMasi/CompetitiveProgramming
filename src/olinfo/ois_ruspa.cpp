#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int n, t;
vector<int> v;

void solve() {
  int a; bool b;
  fin >> a >> b;

  int pos = lower_bound(v.begin(), v.end(), a) - v.begin();
  
  if(pos > n-pos) fout << 0 << " ";
  else if(pos < n-pos) fout << 1 << " ";
  else fout << b << " ";
}

int main() {
  fin >> n >> t;
  v.resize(n);
  for(auto &i : v) fin >> i;

  while(t--) solve();
}