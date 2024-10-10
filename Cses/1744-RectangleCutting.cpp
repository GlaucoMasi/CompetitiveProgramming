#include <bits/stdc++.h>
using namespace std;

int a, b;

int main() {
  cin >> a >> b;
  
  vector<vector<int>> ans(a+1, vector<int>(b+1, 1e9));

  for(int i = 1; i <= a; i++){
    for(int j = 1; j <= b; j++){
      if(i == j){
        ans[i][j] = 0;
        continue;
      }

      for(int k = 1; k <= i-1; k++) ans[i][j] = min(ans[i][j], ans[k][j] + ans[i-k][j] + 1);
      for(int k = 1; k <= j-1; k++) ans[i][j] = min(ans[i][j], ans[i][k] + ans[i][j-k] + 1);
  
    }
  }

  cout << ans[a][b];
}
