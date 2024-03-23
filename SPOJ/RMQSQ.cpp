#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> v;

vector<int> logs;
vector<vector<int>> table;

void init() {
  int t = 2, j = 0; logs.push_back(-1);
  for(int i = 1; i <= n; i++){
    if(i == t){
      t *= 2;
      j++;
    }

    logs.push_back(j);
  }

  table.push_back(v);
  for(int j = 1; j <= logs.back(); j++){
    vector<int> next(n);
    for(int i = 0; i < n; i++){
      if(i+(1<<(j-1)) < n) next[i] = min(table.back()[i], table.back()[i+(1<<(j-1))]);
      else next[i] = table.back()[i];
    }
    table.push_back(next);
  }
}

int main() {
  cin >> n;
  v.resize(n);
  for(auto &i : v) cin >> i;

  init();

  int q; cin >> q;
  while(q--){
    int a, b; cin >> a >> b;
    cout << min(table[logs[b-a+1]][a], table[logs[b-a+1]][b-(1<<logs[b-a+1])+1]) << '\n';
  }
}