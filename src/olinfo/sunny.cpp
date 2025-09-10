#include <bits/stdc++.h>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {

  int N, M, H, S;

  fin >> N >> M >> H >> S;
  H--;
  S--;

  vector<vector<pair<int, int>>> g(N);

  for(int i = 0; i < M; i++) {
    int a, b, l;
    fin >> a >> b >> l;
    
    a--,
    b--;
    
    g[a].push_back({b, l});
    g[b].push_back({a, l});
  }

  vector<bool> vis(N, 0);

  int gallerie = 0;

  while(H != S){

    if(!vis[H])
      vis[H] = 1;
    else{
      gallerie = -1;
      break;
    }

    pair<int, int> sol = {-1, M+1};

    for(auto arco : g[H]){
      if(arco.second < sol.second)
        sol = arco;
    }

    H = sol.first;
    gallerie++;

  }

  fout << gallerie;

}