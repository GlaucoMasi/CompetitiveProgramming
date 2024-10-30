#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int idx = 1;
const int maxv = 5e5+5;

int fail[maxv];
bool done[maxv];
int nxt[maxv][26];
vector<int> inv[maxv], node, best, lenght;

int get(int i){
  if(!done[i]){
    for(auto j : inv[i]) best[i] = min(best[i], get(j));
    done[i] = 1;
  }

  return best[i];
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  string s; cin >> s;

  int m; cin >> m;
  for(int i = 0; i < m; i++){
    int j = 0;
    string t; cin >> t;

    for(auto ch : t){
      int c = ch-'a';
      if(!nxt[j][c]) nxt[j][c] = idx++;
      j = nxt[j][c];
    }

    node.push_back(j);
    lenght.push_back(t.size());
  }

  queue<int> q; q.push(0);
  while(!q.empty()){
    int i = q.front(); q.pop();
    for(int c = 0; c < 26; c++){
      if(nxt[i][c]){
        fail[nxt[i][c]] = i ? nxt[fail[i]][c] : 0;
        inv[fail[nxt[i][c]]].push_back(nxt[i][c]);
        q.push(nxt[i][c]);
      }else nxt[i][c] = nxt[fail[i]][c];
    }
  }

  best.resize(idx, 1e9);
  int j = 0; best[0] = 0;
  for(int i = 1; i <= s.size(); i++){
    j = nxt[j][s[i-1]-'a'];
    best[j] = min(best[j], i);
  }

  for(int i = 0; i < m; i++){
    auto ans = get(node[i]);
    cout << (ans != 1e9 ? ans-lenght[i]+1 : -1) << '\n';
  }
}