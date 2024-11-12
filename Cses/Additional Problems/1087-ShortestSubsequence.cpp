#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  string s; cin >> s;
  int n = s.size();

  vector<vector<int>> nxt(n);
  vector<char> ord = {'A', 'C', 'G', 'T'};

  auto conv = [&](char c){
    if(c == 'A') return 0;
    if(c == 'C') return 1;
    if(c == 'G') return 2;
    if(c == 'T') return 3;
  };

  vector<int> v(4, n);
  for(int i = n-1; i >= 0; i--){
    nxt[i] = v;
    v[conv(s[i])] = i;
  }

  queue<int> q;
  vector<pair<int, char>> anc(n, {-1, '-'});

  for(int i = 0; i < 4; i++){
    if(v[i] == n){
      cout << ord[i];
      return 0;
    }

    q.push(v[i]);
    anc[v[i]] = {-1, ord[i]};
  }

  while(!q.empty()){
    int i = q.front(); q.pop();
    
    for(int j = 0; j < 4; j++){
      if(nxt[i][j] == n){
        string ans = "";
        ans += ord[j];

        while(i != -1){
          ans += anc[i].second;
          i = anc[i].first;
        }

        for(int i = ans.size()-1; i >= 0; i--) cout << ans[i];
        return 0;
      }

      if(anc[nxt[i][j]].second != '-') continue;
      
      anc[nxt[i][j]] = {i, ord[j]};
      q.push(nxt[i][j]);
    }
  }
}