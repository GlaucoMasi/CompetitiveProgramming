#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int n;
vector<vector<pair<int, int>>> g;

pair<int, int> f(int i, int fat){
  pair<int, int> ans = {0, i};

  for(auto j : g[i]){
    if(j.first == fat) continue;
    
    auto t = f(j.first, i);
    ans = max(ans, {j.second + t.first, t.second});
  }

  return ans;
}

int main() {
  fin >> n;
  g.resize(n);

  int a, b, c;
  for(int i = 0; i < n-1; i++){
    fin >> a >> b >> c; a--; b--;
    g[a].push_back({b, c});
    g[b].push_back({a, c});
  }

  fout << f(f(0, -1).second, -1).first;
}