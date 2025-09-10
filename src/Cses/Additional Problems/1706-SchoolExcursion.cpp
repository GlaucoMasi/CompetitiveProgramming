#include <bits/stdc++.h>
using namespace std;

vector<int> num;
vector<int> col;
vector<vector<int>> g;

void f(int i, int c){
  col[i] = c;
  for(auto j : g[i]) if(col[j] == -1) f(j, c);
}

int main() {
  int n, m; cin >> n >> m;
  g.resize(n); col.resize(n, -1);

  for(int i = 0; i < m; i++){
    int a, b; cin >> a >> b;
    g[a-1].push_back(b-1);
    g[b-1].push_back(a-1);
  }

  int idx = 0;
  for(int i = 0; i < n; i++){
    if(col[i] == -1){
      f(i, idx);
      idx++;
    }
  }

  num.resize(idx);
  for(auto i : col) num[i]++;

  bitset<100001> b; b.set(0, 1);
  for(auto i : num) b |= (b<<i);

  for(int i = 1; i <= n; i++) cout << b[i];
}