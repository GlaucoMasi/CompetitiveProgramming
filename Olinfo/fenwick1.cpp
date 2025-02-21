#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

vector<vector<int>> g;
vector<int> sz, ord, start, idx;

int f(int i){
  ord.push_back(i);
  idx[i] = ord.size()-1;
  for(auto j : g[i]) sz[i] += f(j);
  return sz[i];
}

const int maxn = 5e5+2;
int fen[maxn];

void add(int i, int k){
  while(i < maxn){
    fen[i] += k;
    i += (i&-i);
  }
}

int get(int i){
  int ans = 0;
  while(i > 0){
    ans += fen[i];
    i -= (i&-i);
  }
  return ans;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  int n, m; fin >> n >> m;
  sz.resize(n, 1);
  g.resize(n);
  start.resize(n);
  idx.resize(n);

  fin >> start[0];
  for(int i = 1; i < n; i++){
    int p;
    fin >> start[i] >> p;
    g[p-1].push_back(i);
  }

  f(0);
  for(int i = 0; i < n; i++){
    add(idx[i]+1, start[i]);
    add(idx[i]+2, -start[i]);
  }

  while(m--){
    char c; fin >> c;
    if(c == 'p'){
      int i, x; fin >> i >> x; i--;
      add(idx[i]+2, x);
      add(idx[i]+sz[i]+1, -x);
    }else{
      int i; fin >> i; i--;
      fout << get(idx[i]+1) << '\n';
    }
  }
}