#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int n;
vector<int> cost;
vector<vector<int>> g;

vector<vector<long long>> memo;

vector<int> lista;

long long f(int i, int fat, bool col){
  if(memo[i][col] != -1) return memo[i][col];

  long long coloro = cost[i];
  long long noncoloro = col ? 1e9 : 0;

  for(auto j : g[i]){
    if(j == fat) continue;

    coloro += f(j, i, 0);
    if(!col) noncoloro += f(j, i, 1);
  }

  if(coloro < noncoloro) return memo[i][1] = coloro;
  else return memo[i][0] = noncoloro;
}

void build(int i, int fat, bool col){
  if(col || (memo[i][1] < memo[i][0] && memo[i][1] != -1) || memo[i][0] == -1) lista.push_back(i);

  for(auto j : g[i]){
    if(j != fat) build(j, i, (!(col || (memo[i][1] < memo[i][0] && memo[i][1] != -1) || memo[i][0] == -1)));
  }
}

int main() {
  fin >> n;
  
  memo.resize(n, vector<long long>(2, -1));

  cost.resize(n);
  for(auto &i : cost) fin >> i;
  
  g.resize(n);
  int a, b;
  for(int i = 0; i < n-1; i++){
    fin >> a >> b;
    g[a-1].push_back(b-1);
    g[b-1].push_back(a-1);
  }

  f(0, -1, 0);

  build(0, -1, 0);

  fout << '\n' << lista.size() << '\n';
  for(auto i : lista) fout << i+1 << " ";
}