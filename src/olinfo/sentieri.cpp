#include <bits/stdc++.h>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

using type = pair<int, int>;
const int INF = 10e5;

int main() {

  fin.tie(0);
  fin.sync_with_stdio(0);

  int n, a, b;
  fin >> n >> a >> b;

  vector<vector<pair<int, int>>> g(n);

  for(int i = 0; i < a; i++){
    int a, b;
    fin >> a >> b;
    a--; b--;

    g[a].push_back({b, 0});
    g[b].push_back({a, 0});
  }

  for(int i = 0; i < b; i++){
    int a, b;
    fin >> a >> b;
    a--; b--;

    g[a].push_back({b, 1});
    g[b].push_back({a, 1});
  }

  vector<int> d(n, INF);

  priority_queue<type, vector<type>, greater<type>> pq;

  d[0] = 0;
  pq.push({0, 0});

  while(!pq.empty()){
    type current = pq.top();
    pq.pop();

    int node = current.second;
    int bol = current.first;

    if(d[node] < bol) continue;

    for(auto &e : g[node]){
      if(d[e.first] > d[node] + e.second){
        d[e.first] = d[node] + e.second;
        pq.push({d[e.first], e.first});   
      }
    }
  }
  fout << d[n-1];
}