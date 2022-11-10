#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m; cin >> n >> m;
  vector<int> masc(n), femm(m);
  for(auto &i : masc) cin >> i;
  for(auto &i : femm) cin >> i;

  vector<vector<int>> ans(n, vector<int>(m));
  for(int i = n-1; i >= 0; i--){
    for(int j = m-1; j >= 0; j--){
      int stay = abs(masc[i]-femm[j]) + ((i < n-1 && j < m-1) ? ans[i+1][j+1] : 0);

      int switch_m = (i < n-1) ? ans[i+1][j] : 0;
      int switch_f = (j < m-1) ? ans[i][j+1] : 0;
    
      ans[i][j] = max(stay, max(switch_m, switch_f));
    }
  }

  cout << ans[0][0];
}