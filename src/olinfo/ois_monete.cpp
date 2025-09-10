#include <bits/stdc++.h>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
  
  fin.tie(0);
  fin.sync_with_stdio(0);

  int N, M;
  int somma = 0;

  fin >> N >> M;

  vector<int> monete(N);
  vector<vector<int>> g(N);

  for(int &i : monete){
    fin >> i;
  }

  for(int i = 0; i < M; i++){
    int a, b;
    fin >> a >> b;

    g[a].push_back(b);
    g[b].push_back(a);
  }

  queue<int> coda;
  coda.push(0);

  vector<bool> vis(N);
  vis[0] = 1;

  while(!coda.empty()){
    int current = coda.front();
    coda.pop();

    for(int vicino : g[current]){
      if(!vis[vicino]){
        vis[vicino] = 1;
        coda.push(vicino);
      }
    }
  }

  for(int i = 0; i < N; i++){
    if(vis[i] == 1){
      somma += monete[i];
    }
  }

  fout << somma;

}