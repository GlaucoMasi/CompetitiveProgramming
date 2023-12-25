#include <bits/stdc++.h>
using namespace std;

map<int, int> s;
vector<vector<int>> criv;

int controlla(int c){
  int ans = 0;
  for(auto t : criv[c]) if(s.count(t)) ans = s[t];
  if(!ans) for(auto t : criv[c]) s[t] = c;

  return ans;
}

void inizializza(int p, int m){ 
  criv.resize(m+1);
  for(int i = 2; i <= m; i++){
    if(criv[i].empty()) for(int j = i; j <= m; j += i) criv[j].push_back(i);
  }
}