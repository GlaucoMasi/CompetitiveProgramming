#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int idx = 1;
const int maxv = 3e5;

int nxt[maxv][26];
int lenght[maxv], back[maxv];
vector<long long> cnt(maxv, -1);

long long calc(int i){
  if(cnt[i] != -1) return cnt[i];
  cnt[i] = 1;
  for(int j = 0; j < 26; j++) if(nxt[i][j]) cnt[i] += calc(nxt[i][j]);
  return cnt[i];
}

string ans = "";
void dfs(int i, long long k){
  if(k == 0) return;
  else k--;

  for(int j = 0; j < 26; j++){
    if(!nxt[i][j]) continue;
    if(cnt[nxt[i][j]] > k){
      ans += ('a'+j);
      dfs(nxt[i][j], k);
      return;
    }else k -= cnt[nxt[i][j]];
  }
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  string s;
  long long k;
  cin >> s >> k;

  int last = 0; back[0] = -1;
  for(auto ch : s){
    int c = ch-'a', i = last, curr = idx++;
    lenght[curr] = lenght[i]+1;

    while(i != -1 && !nxt[i][c]){
      nxt[i][c] = curr;
      i = back[i];
    }

    if(i == -1) back[curr] = 0;
    else{
      int q = nxt[i][c];

      if(lenght[q] == lenght[i]+1) back[curr] = q;
      else{
        int clone = idx++;

        for(int k = 0; k < 26; k++) nxt[clone][k] = nxt[q][k];
        back[clone] = back[q];
        lenght[clone] = lenght[i]+1;
      
        while(i != -1 && nxt[i][c] == q){
          nxt[i][c] = clone;
          i = back[i];
        }

        back[curr] = back[q] = clone;
      }
    }

    last = curr;
  }

  calc(0);
  cnt[0] = 1;
  dfs(0, k);
  cout << ans;
}
