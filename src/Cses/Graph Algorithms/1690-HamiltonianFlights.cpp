#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
  int mod = 1e9+7;
  int n, m; cin >> n >> m;
  vector<vector<int>> g(n);
  vector<vector<int>> memo(1<<n, vector<int>(n));
  
  int a, b;
  for(int i = 0; i < m; i++){
    cin >> a >> b;
    g[b-1].push_back(a-1);
  }

  memo[1][0] = 1;
  for(int i = 0; i < 1<<n; i++){
    if(!(i & (1<<0))) continue;

    for(int j = 0; j < n; j++){
      for(auto k : g[j])
        if((i & (1<<j))) memo[i][j] = (memo[i][j] + memo[i^(1<<j)][k])%mod;
    }
  }

  cout << memo[(1<<n)-1][n-1];
}