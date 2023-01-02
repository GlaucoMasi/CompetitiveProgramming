#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
  int mod = 1e9+7;
  int n, m; fin >> n >> m;

  vector<vector<int>> v(n, vector<int>(m));
  for(auto &i : v) for(auto &j : i) fin >> j;

  vector<vector<pair<int, int>>> memo(1<<n, vector<pair<int, int>>(m+1));

  for(int i = 0; i < 1<<n; i++){
    memo[i][0] = {0, 1};

    for(int j = 1; j <= m; j++){
      memo[i][j] = memo[i][j-1];

      for(int k = 0; k < n; k++){
        if(i & (1<<k) && v[k][j-1]){
          if(memo[i^(1<<k)][j-1].first+1 > memo[i][j].first){
            memo[i][j] = memo[i^(1<<k)][j-1];
            memo[i][j].first++;
          }else if(memo[i^(1<<k)][j-1].first+1 == memo[i][j].first) memo[i][j].second = (memo[i][j].second + memo[i^(1<<k)][j-1].second)%mod;
        }
      }
    }
  }

  fout << memo[(1<<n)-1][m].second;
}