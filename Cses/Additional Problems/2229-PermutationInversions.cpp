#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  int mod = 1e9+7;
  int n, k; cin >> n >> k;
  vector<vector<long long>> v(n+1, vector<long long>(k+1));
  fill(v[0].begin(), v[0].end(), 1);

  auto get = [&](int i, int l, int r){
    return (v[i][r] - (l ? v[i][l-1] : 0) + mod)%mod;
  };

  for(int i = 1; i <= n; i++){
    for(int j = 0; j <= k; j++){
      v[i][j] = get(i-1, j-min(j, i-1), j);
      if(j) v[i][j] = (v[i][j]+v[i][j-1])%mod;
    }
  }

  cout << get(n, k, k);
}