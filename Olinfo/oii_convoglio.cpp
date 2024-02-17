#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int n, m;
vector<vector<int>> g;
vector<int> fat, status, first;

bool f(int i, int j){
  if(status[i] == 2) return 0;

  fat[i] = j;

  if(status[i] == 1){
    vector<bool> pres(n);
    vector<pair<int, int>> ans;

    int k = i;
    do{
      ans.push_back({k, fat[k]-n});
      pres[k] = 1;
      k = fat[fat[k]];
    }while(k != i);
    
    for(auto j = 0; j < n; j++) if(!pres[j]) ans.push_back({j, first[j]});
    sort(ans.begin(), ans.end());
    for(auto i : ans) fout << i.first << " " << i.second << '\n';

    status[i] = 2;
    return 1;
  }

  bool ans = 0;
  status[i] = 1;
  for(auto k : g[i]) if(f(k, i)){
    ans = 1;
    break;
  }

  status[i] = 2;
  return ans;
}

int main() {
  fin >> n >> m;
  g.resize(2*n);
  status.resize(2*n);
  first.resize(n);
  fat.resize(2*n, -1);

  int a, b;
  for(int i = 0; i < m; i++){
    fin >> a >> b; b += n;

    if(i < n){
      first[a] = b-n;
      g[a].push_back(b);
    }else g[b].push_back(a);
  }

  for(int i = 0; i < n; i++) if(!status[i] && f(i, -1)) return 0;
  fout << -1;
}