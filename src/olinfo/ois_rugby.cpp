#include <bits/stdc++.h>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int n;
vector<vector<int>> g;
vector<int> v;

int f(int node){
  int somma = 0;

  for(auto i : g[node]){
    somma += f(i);
  }

  return max(v[node], somma);
}

int main() {
  fin >> n;
  v.resize(n);
  g.resize(n);

  for(int i = 0; i < n; i++){
    fin >> v[i];

    int a; fin >> a;
    if(a != -1) g[a].push_back(i);
  }

  fout << f(0);
}