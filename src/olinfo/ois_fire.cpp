#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> g;
vector<int> memo, totale;
vector<pair<int, int>> grandi;

void calc(int i, int fat){
  for(auto j : g[i]){
    if(j == fat) continue;
    
    calc(j, i);

    totale[i] += memo[j];
    if(memo[j] > grandi[i].first){
      grandi[i].second = grandi[i].first;
      grandi[i].first = memo[j];
    }else if(memo[j] > grandi[i].second) grandi[i].second = memo[j];
  }

  memo[i] = totale[i] - grandi[i].first;
}

void f(int i, int fat){
  int newson = totale[fat] - memo[i];

  if(memo[i] == grandi[fat].first) newson -= grandi[fat].second;
  else newson -= grandi[fat].first;

  if(newson > grandi[i].first){
    grandi[i].second = grandi[i].first;
    grandi[i].first = newson;
  }else if(newson > grandi[i].second) grandi[i].second = newson;

  totale[i] += newson;
  memo[i] = totale[i] - grandi[i].first;

  for(auto j : g[i]) if(j != fat) f(j, i);
}

int main() {
  cin >> n;
  g.resize(n);

  memo.resize(n);
  totale.resize(n, 1);
  grandi.resize(n, {0, 0});

  int a, b;
  for(int i = 0; i < n-1; i++){
    cin >> a >> b;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  calc(0, -1);
  for(auto i : g[0]) f(i, 0);
  for(auto i : memo) cout << i << " ";
}