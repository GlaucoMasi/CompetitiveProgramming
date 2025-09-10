#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int idx = 1;
const int maxv = 3e5;
int nxt[maxv][26];
int back[maxv], len[maxv];

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  int last = 0; back[last] = -1;
  string s; cin >> s;
  for(auto ch : s){
    int c = ch-'a';

    int curr = idx++, i = last;
    len[curr] = len[last]+1;

    while(i != -1 && !nxt[i][c]){
      nxt[i][c] = curr;
      i = back[i];
    }

    if(i == -1) back[curr] = 0;
    else{
      if(len[nxt[i][c]] == len[i]+1) back[curr] = nxt[i][c];
      else{
        int clone = idx++, q = nxt[i][c];

        for(int k = 0; k < 26; k++) nxt[clone][k] = nxt[q][k];
        back[clone] = back[q];
        len[clone] = len[i]+1;

        while(i != -1 && nxt[i][c] == q){
          nxt[i][c] = clone;
          i = back[i];
        }

        back[curr] = back[q] = clone;
      }
    }

    last = curr;
  }

  long long ans = 0;
  for(int i = 1; i < idx; i++) ans += (long long)(len[i]-len[back[i]]);
  cout << ans;
}