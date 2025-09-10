#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

vector<vector<int>> g;
vector<int> nodes, figli;
vector<bool> visited;

int f(int i){
  if(nodes[i] < 3) figli[nodes[i]]++;
  visited[i] = 1;

  int tot = 1;
  for(auto j : g[i]){
    if(!visited[j]) tot += f(j);
  }

  return tot;
}

void Analizza(int N, int M, int A[], int B[], int T[]){
  g.resize(N);
  nodes.resize(N, 0);
  visited.resize(N, 0);
  figli.resize(4, 0);

  for(int i = 0; i < M; i++){
    A[i]--; B[i]--;
    g[A[i]].push_back(B[i]);
    g[B[i]].push_back(A[i]);

    nodes[A[i]]++;
    nodes[B[i]]++;
  }

  for(int i = 0; i < N; i++){
    if(!visited[i]){
      figli.clear();
      figli.resize(4, 0);
      
      int tot = f(i);

      if(figli[1] == 2 && figli[2] == tot-2) T[0]++;
      else if(figli[2] == tot) T[1]++;
      else if(figli[1] == tot-1 && tot != 1) T[2]++;
    }
  }
}