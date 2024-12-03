#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  string s; cin >> s;

  int idx = 0;
  vector<int> match(26, -1);
  for(auto &i : s){
    if(match[i-'a'] == -1) match[i-'a'] = idx++;
    i = 'a'+match[i-'a'];
  }

  long long ans = 0;
  map<vector<int>, int> m;
  vector<int> freq(idx);
  m[freq]++;

  for(auto i : s){
    if(i == 'a') for(int j = 1; j < idx; j++) freq[j]--;
    else freq[i-'a']++;

    ans += m[freq];
    m[freq]++;
  }

  cout << ans;
}