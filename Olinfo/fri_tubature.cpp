#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

vector<vector<int>> g;
vector<int> guardie;
vector<bool> centrali, check;

int f(int i){
  if(centrali[i]) return guardie[i];

  int skip = 0;
  for(auto j : g[i]) skip += f(j);

  return min(skip, guardie[i]);
}

int pianifica(int n, int m, int da[], int a[], int C[], int G[]){
  g.resize(n);
  guardie.resize(n);
  centrali.resize(n);
  check.resize(n, 1);

  for(int i = 0; i < n; i++) guardie[i] = G[i];
  for(int i = 0; i < m; i++) centrali[C[i]] = 1;
  
  for(int i = 0; i < n-1; i++){
    g[da[i]].push_back(a[i]);
    check[a[i]] = 0;
  }

  for(int i = 0; i < n; i++){
    if(check[i]) return f(i);
  }
}