#include <bits/stdc++.h>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

vector<vector<pair<int, int>>> g;

int main(){
  int n, m, s, p;
  fin >> n >> m >> s >> p;
  s--; p--;
  g.resize(n);

  for(int i = 0; i < m; i++){
    int a, b, c; fin >> a >> b >> c;
    a--; b--;

    g[a].push_back({b, c});
  }

  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
  vector<long long> d(n, -1);
  vector<bool> vis(n);
  d[s] = 0;
  q.push({0, s});
  
  while(!q.empty()){
    int nodo = q.top().second;
    q.pop();

    if(vis[nodo]){
      if(nodo == p) break;
      else continue;
    }
    vis[nodo] = 1;

    for(auto i : g[nodo]){
      if(d[i.first] > d[nodo] + i.second || d[i.first] == -1){
        d[i.first] = d[nodo] + i.second;
        q.push({d[i.first], i.first});
      }
    }
  }

  fout << d[p];
}