#include <bits/stdc++.h>
using namespace std;

int n, c;
vector<string> v;
vector<vector<pair<int, pair<int, int>>>> memo;
vector<pair<int, int>> best;
vector<vector<vector<int>>> over;

int main() {
  cin >> n >> c;
  v.resize(n); for(auto &i : v) cin >> i;
  memo.resize(c, vector<pair<int, pair<int, int>>>(n));
  best.resize(c);
  over.resize(n, vector<vector<int>>(4));

  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      for(int k = 1; k < 4; k++){
        if(v[i].substr(k, 4-k) == v[j].substr(0, 4-k)) over[i][k].push_back(j);
      }
    }
  }
  
  for(int i = 0; i < n; i++) memo[c-4][i] = {1, {c, -1}}; best[c-4] = {1, 0};
  for(int i = c-5; i >= 0; i--){
    for(int j = 0; j < n; j++){
      string curr = v[j];
      
      if(i+4 <= c-4) memo[i][j] = {best[i+4].first+1, {i+4, best[i+4].second}};
      else memo[i][j] = {1, {c, -1}};

      for(int off = 1; off < 4; off++){
        for(auto k : over[j][off]){
          if(i+off > c-4) continue;
          memo[i][j] = max(memo[i][j], {memo[i+off][k].first+1, {i+off, k}});
        }
      }

      best[i] = max(best[i], {memo[i][j].first, j});
    }
  }

  vector<char> ans(c, '0');
  int i = 0, k = max_element(memo[0].begin(), memo[0].end())-memo[0].begin();
  while(i != c){
    for(int j = 0; j < 4; j++) ans[i+j] = v[k][j];

    int nexti = memo[i][k].second.first;
    k = memo[i][k].second.second, i = nexti;
  }

  for(auto i : ans) cout << i;
}