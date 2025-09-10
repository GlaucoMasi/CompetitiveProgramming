#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  int ins, del, rep, exc;
  fin >> ins >> del >> rep >> exc;

  string a, b; fin >> a >> b;
  vector<vector<int>> dp(a.size()+1, vector<int>(b.size()+1, 1e9));

  dp[0][0] = 0;
  for(int i = 1; i <= a.size(); i++) dp[i][0] = del*i;
  for(int i = 1; i <= b.size(); i++) dp[0][i] = ins*i;

  int same;
  vector<int> last(26);
  for(int i = 1; i <= a.size(); i++){
    same = 0;

    for(int j = 1; j <= b.size(); j++){
      dp[i][j] = min(dp[i][j], dp[i-1][j-1] + rep*(a[i-1] != b[j-1]));
      dp[i][j] = min(dp[i][j], dp[i-1][j] + del);
      dp[i][j] = min(dp[i][j], dp[i][j-1] + ins);

      if(a[i-1] == b[j-1]) same = j;
      else{
        int li = last[b[j-1]-'a'], lj = same;
        if(li && lj) dp[i][j] = min(dp[i][j], dp[li-1][lj-1] + exc + ins*(j-lj-1) + del*(i-li-1));
      }
    }

    last[a[i-1]-'a'] = i;
  }

  fout << dp[a.size()][b.size()];
}