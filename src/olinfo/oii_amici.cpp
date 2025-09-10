#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int n, k, t;
vector<int> v, cycle;

vector<vector<int>> paths;
vector<int> temp;
map<int, pair<int, int>> mp;

int f(int i, int d){
  if(cycle[i] == 0) return d;
  cycle[i] = 0;
  temp.push_back(i);
  
  return cycle[i] = f(v[i]-1, d+1);
}

int main() {
  fin >> n >> k >> t;
  v.resize(n); for(auto &i : v) fin >> i;
  cycle.resize(n, -1);

  for(int i = 0; i < n; i++){
    if(cycle[i] == -1){
      temp.clear();
      cycle[i] = f(v[i]-1, 0);
      paths.push_back(temp);
      for(int i = 0; i < temp.size(); i++) mp[temp[i]] = {paths.size()-1, i};
    }
  }

  vector<bool> ans(n);
  while(k--){
    int a; fin >> a; a--;

    int left = t%cycle[a];

    int idx = mp[a].second + left;
    idx %= cycle[a];
    a = paths[mp[a].first][idx];
    ans[a] = 1;
  }

  int i = 0;
  while(!ans[i]) i++;

  if(i != 0) fout << i+1;
  else{
    i = n-1;
    while(ans[i]) i--;
    fout << i+2;
  }
}