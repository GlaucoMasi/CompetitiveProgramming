#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

void nuovo_gruppo();
void aggiungi(int bambino);

int curr = 0;
vector<int> col;
vector<vector<int>> groups, g;

void f(int i){
  vector<bool> choose(curr+1);
  
  for(auto j : g[i]) if(col[j] != -1) choose[col[j]] = 1;
  
  int j = 0;
  while(1){
    if(j == curr+1) break;

    if(!choose[j]){
      col[i] = j;
      groups[j].push_back(i);
      break;
    }

    j++;
  }

  if(j == curr+1){
    curr++;
    col[i] = curr;

    if(groups.size() < curr+1) groups.push_back({});
    groups[curr].push_back(i);
  }

  for(auto j : g[i]) if(col[j] == -1) f(j);
}

void smista(int n, int* nemico){
  col.resize(n, -1);
  g.resize(n);
  groups.push_back({});

  for(int i = 0; i < n; i++){
    g[i].push_back(nemico[i]);
    g[nemico[i]].push_back(i);
  }

  for(int i = 0; i < n; i++){
    curr = 0;
    if(col[i] == -1) f(i);
  }

  for(auto i : groups){
    nuovo_gruppo();
    for(auto j : i) aggiungi(j);
  }
}