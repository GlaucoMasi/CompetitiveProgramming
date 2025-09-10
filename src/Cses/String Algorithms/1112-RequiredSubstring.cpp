#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

string s;
long long ans = 0;
int n, m, mod = 1e9+7;
vector<vector<int>> nxt;
vector<int> pref;

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  cin >> n >> s; m = s.size();
  nxt.resize(s.size(), vector<int>(26));
  pref.resize(s.size());

  for(int i = 1; i < m; i++){
    int j = pref[i-1];
    while(j > 0 && s[i] != s[j]) j = pref[j-1];
    if(s[i] == s[j]) j++;
    pref[i] = j;
  }

  for(int i = 1; i < m; i++) for(int c = 0; c < 26; c++){
    int j = pref[i-1];
    while(j > 0 && s[j] != 'A'+c) j = pref[j-1];
    if(s[j] == 'A'+c) j++;
    nxt[i][c] = j;
  }

  vector<vector<int>> dp(n+1, vector<int>(m+1));
  for(int i = 0; i < m; i++) dp[n][i] = 1;
  for(int i = n-1; i >= 0; i--) for(int j = 0; j < m; j++){
    dp[i][j] = (dp[i][j]+dp[i+1][j+1])%mod;
    for(int c = 0; c < 26; c++) if(s[j] != 'A'+c) dp[i][j] = (dp[i][j]+dp[i+1][nxt[j][c]])%mod;
  }

  long long t = 1;
  while(n--) t = (t*26LL)%mod;
  cout << (t-dp[0][0]+mod)%mod;
}