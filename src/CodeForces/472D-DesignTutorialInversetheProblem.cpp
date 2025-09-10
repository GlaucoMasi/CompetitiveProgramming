#include <bits/stdc++.h>
using namespace std;

int v[2001][2001];
vector<pair<int, int>> g[2001];

bool f(int i, int prev, int first, int l){
  if(v[first][i] != l) return 0;

  for(auto j : g[i]){
    if(j.first == prev) continue;
    if(!f(j.first, i, first, l+j.second)) return 0;
  }

  return 1;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  int n; cin >> n;

  for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) cin >> v[i][j];

  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      if((i == j && v[i][j]) || (i != j && (!v[i][j] || v[i][j] != v[j][i]))){
        cout << "NO";
        return 0;
      }
    }
  }

  bool taken[n] = {0}; taken[0] = 1;
  pair<int, int> shortest[n];
  for(int i = 1; i < n; i++) shortest[i] = {v[0][i], 0};

  for(int i = 0; i < n-1; i++){
    pair<pair<int, int>, int> next; next.first.first = 1e9;
    for(int j = 0; j < n; j++) if(!taken[j]) next = min(next, {shortest[j], j});

    int a = next.first.second, b = next.second;
    g[a].push_back({b, v[a][b]});
    g[b].push_back({a, v[a][b]});
    taken[b] = 1;

    for(int j = 0; j < n; j++) shortest[j] = min(shortest[j], {v[b][j], b});
  }


  for(int i = 0; i < n; i++){
    if(!f(i, -1, i, 0)){
      cout << "NO";
      return 0;
    }
  }

  cout << "YES";
  return 0;
}