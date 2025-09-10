#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

const int INF = 10e6;

// n -> cabine
// m -> corridoi
// c -> tesoro
// k -> sacche d'aria

int main() {
  fin.tie(0);
  fin.sync_with_stdio(0);

  int n, m , c, k;
  fin >> n >> m >> c >> k;
  c--;

  vector<bool> aria(n);

  for(int i = 0; i < k; i++){
    int a; 
    fin >> a;
    a--;
    aria[a] = true;
  }

  vector<vector<pair<int, int>>> g(n);
  for(int i = 0; i < m; i++){
    int a, b, c;
    fin >> a >> b >> c;
    a--; b--;

    g[a].push_back({b, c});
    g[b].push_back({a, c});
  }

  queue<pair<int, int>> q;
  vector<int> d(n, INF);

  d[0] = 0;
  q.push({0, 20});

  while(!q.empty()){
    pair<int, int> curr = q.front();
    q.pop();

    int node = curr.first;
    int a = aria[node] ? 20 : curr.second;

    for(auto arco : g[node]){
      if(d[arco.first] > d[node] + arco.second && a >= arco.second){
        d[arco.first] = d[node] + arco.second;

        q.push({arco.first, a - arco.second});
      } 
    }
  }

  d[c] = d[c] == INF ? -1 : d[c];
  fout << d[c];
}