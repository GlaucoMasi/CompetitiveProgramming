#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int n, q;
vector<vector<int>> father;

int main() {
  cin >> n >> q;
  father.resize(n, vector<int>(log2(4*n)));

  father[0][0] = 0;
  for(int i = 1; i < n; i++) cin >> father[i][0];

  // posso invertire i due for se l'ordine dei nodi in profondità non è sempre crescente
  // i.e. father[i] > i
  for(int i = 0; i < n; i++){
    father[i][0]--;

    for(int j = 1; j < log2(2*n); j++){
      father[i][j] = father[i][j-1] == -1 ? -1 : father[father[i][j-1]][j-1]; 
    }
  }

  int u, k;
  while(q--){
    cin >> u >> k;
    u--;

    for(int j = 0; j < log2(2*n); j++){
      if(k & (1<<j)){
        u = father[u][j];
      }

      if(u == -1) break;
    }

    cout << (u != -1 ? u+1 : u) << '\n';
  }
}