#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
  string a; vector<string> v;
  while(fin >> a) v.push_back(a+'.'); a += '.';
  vector<vector<vector<int>>> g(v.size(), vector<vector<int>>(a.size()));

  int ans = 0;
  for(int j = 0; j < v.size(); j++){
    int curr = 0;
    set<pair<int, int>> pos;

    for(int i = 0; i < a.size(); i++){
      int c = v[j][i]-'0';
      if(c > 9 || c < 0){
        for(auto [a, b] : pos) g[a][b].push_back(curr);
        curr = 0; pos.clear();
        continue;
      }

      curr *= 10; curr += c;
      
      if(j > 0){
        if(i > 0 && v[j-1][i-1] == '*') pos.insert({j-1, i-1});
        if(v[j-1][i] == '*') pos.insert({j-1, i});
        if(i+1 < a.size() && v[j-1][i+1] == '*') pos.insert({j-1, i+1});
      }

      if(j+1 < v.size()){
        if(i > 0 && v[j+1][i-1] == '*') pos.insert({j+1, i-1});
        if(v[j+1][i] == '*') pos.insert({j+1, i});
        if(i+1 < a.size() && v[j+1][i+1] == '*') pos.insert({j+1, i+1});
      }

      if(i > 0 && v[j][i-1] == '*') pos.insert({j, i-1});
      if(i+1 < a.size() && v[j][i+1] == '*') pos.insert({j, i+1});
    }
  }

  for(auto i : g){
    for(auto j : i){
      if(j.size() != 2) continue;
      ans += j[0]*j[1];
    }
  }

  fout << ans;
}