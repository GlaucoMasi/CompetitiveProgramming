#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int n, m, a, b;
vector<set<int>> g;

int main() {
  fin >> n >> m >> a >> b;
  g.resize(n);
  a--; b--;
  
  for(int i = 0; i < m; i++){
    int o, p; fin >> o >> p;
    o--; p--;
    g[o].insert(p);
    g[p].insert(o);
  }

  vector<int> path;
  stack<int> s; s.push(b);
  while(!s.empty()){
    if(!g[s.top()].size()){
      path.push_back(s.top());
      s.pop();
    }else{
      int next = *g[s.top()].begin();
      g[s.top()].erase(next);
      g[next].erase(s.top());

      s.push(next);
    }
  }

  for(int i = 1; i < path.size(); i++) fout << path[i-1]+1 << " " << path[i]+1 << '\n'; 
}