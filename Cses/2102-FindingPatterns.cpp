#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int idx = 1;
const int maxv = 5e5+5;

int fail[maxv];
int nxt[maxv][26];
bool done[maxv], vis[maxv];
vector<int> inv[maxv], node;

int get(int i){
  if(!done[i]){
    for(auto j : inv[i]) vis[i] |= get(j);
    done[i] = 1;
  }

  return vis[i];
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  string s; cin >> s;
  int m; cin >> m;
  for(int i = 1; i <= m; i++){
    string t; cin >> t;
    int j = 0;

    for(auto ch : t){
      int c = ch-'a';
      if(!nxt[j][c]) nxt[j][c] = idx++;
      j = nxt[j][c];
    }

    node.push_back(j);
  }

  queue<int> q; q.push(0);
  while(!q.empty()){
    int i = q.front(); q.pop();
    for(int c = 0; c < 26; c++){
      if(nxt[i][c]){
        fail[nxt[i][c]] = (i ? nxt[fail[i]][c] : 0);
        inv[fail[nxt[i][c]]].push_back(nxt[i][c]);
        q.push(nxt[i][c]);
      }else nxt[i][c] = nxt[fail[i]][c];
    }
  }

  int j = 0; vis[j] = 1;
  for(auto ch : s){
    j = nxt[j][ch-'a'];
    vis[j] = 1;
  }

  for(int i = 0; i < m; i++) cout << (get(node[i]) ? "YES\n" : "NO\n");
}