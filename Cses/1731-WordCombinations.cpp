#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int mod = 1e9+7, idx = 1;
vector<vector<int>> trie(1e6+5, vector<int>(26));
vector<bool> word(1e6+5);

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  string s; cin >> s;
  int n; cin >> n;

  while(n--){
    string a; cin >> a;
    int t = 0;
    for(int j = 0; j < a.size(); j++){
      if(!trie[t][a[j]-'a']) trie[t][a[j]-'a'] = idx++;
      t = trie[t][a[j]-'a'];
    }

    word[t] = 1;
  }

  vector<int> dp(s.size()+1); dp[s.size()] = 1;
  for(int i = s.size()-1; i >= 0; i--){
    int t = 0;
    for(int j = i; j < s.size(); j++){
      if(!trie[t][s[j]-'a']) break;
      t = trie[t][s[j]-'a'];
      if(word[t]) dp[i] = (dp[i]+dp[j+1])%mod;
    }
  }

  cout << dp[0];
}