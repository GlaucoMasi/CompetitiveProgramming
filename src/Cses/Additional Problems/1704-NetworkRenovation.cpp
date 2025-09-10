#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int n;
vector<vector<int>> g;
vector<int> leaves;

void f(int i, int p){
  for(auto j : g[i]) if(j != p) f(j, i);
  if(g[i].size() == 1) leaves.push_back(i+1);
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  cin >> n;
  g.resize(n);

  for(int i = 0; i < n-1; i++){
    int a, b; cin >> a >> b;
    g[--a].push_back(--b);
    g[b].push_back(a);
  }

  f(0, -1);

  cout << (leaves.size()+1)/2 << '\n';
  for(int i = 0; i < leaves.size()/2; i++) cout << leaves[i] << " " << leaves[leaves.size()/2+i] << '\n';
  if(leaves.size()%2) cout << leaves[0] << " " << leaves.back();
}