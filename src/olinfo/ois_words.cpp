#include <bits/stdc++.h>
using namespace std;

#define cap (long long)(2e18)

int main() {
  long long n; int l, k;
  cin >> n >> l >> k;

  long long dp[l][26][26];
  vector<int> succ[26][26];

  for(int i = 0; i < k; i++){
    string s; cin >> s;
    succ[s[0]-'a'][s[1]-'a'].push_back(s[2]-'a');
  }

  for(int i = 0; i < 26; i++){
    for(int j = 0; j < 26; j++){
      sort(succ[i][j].begin(), succ[i][j].end());
      dp[l-2][i][j] = 1;
    }
  }

  for(int i = l-3; i >= 0; i--){
    for(int j = 0; j < 26; j++){
      for(int t = 0; t < 26; t++){
        for(auto z : succ[j][t]){
          dp[i][j][t] += dp[i+1][t][z];
          dp[i][j][t] = min(dp[i][j][t], cap);
        }
      }
    }
  }

  int a = -1, b = -1;
  for(int i = 0; i < 26 && a == -1; i++){
    for(int j = 0; j < 26 && b == -1; j++){
      if(dp[0][i][j] < n) n -= dp[0][i][j];
      else{
        a = i;
        b = j;
      }
    }
  }

  for(int i = 0; i < l-2; i++){
    cout << (char)('a'+a);

    for(auto t : succ[a][b]){
      if(dp[i+1][b][t] < n) n -= dp[i+1][b][t];
      else{
        a = b;
        b = t;
        break;
      }
    }
  }

  cout << (char)('a'+a) << (char)('a'+b);
}