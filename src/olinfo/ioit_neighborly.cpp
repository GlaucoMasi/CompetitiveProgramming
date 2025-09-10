#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int idx = 1;
const int maxn = 3e5;
unordered_map<int, int> nxt[maxn];
int back[maxn], len[maxn];

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  string a, b;
  getline(cin, a);
  getline(cin, b);

  int last = 0; back[0] = -1;
  for(auto c : b){
    int curr = idx++, i = last;
    len[curr] = len[last]+1;

    while(i != -1 && !nxt[i].count(c)){
      nxt[i][c] = curr;
      i = back[i];
    }

    if(i == -1) back[curr] = 0;
    else{
      if(len[nxt[i][c]] == len[i]+1) back[curr] = nxt[i][c];
      else{
        int clone = idx++, q = nxt[i][c];
        
        nxt[clone] = nxt[q];
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

  int ans = 0, i = 0;
  while(i < a.size()){
    int idx = 0; ans++;
    while(nxt[idx].count(a[i])){
      idx = nxt[idx][a[i]];
      i++;
    }
  }

  cout << ans;
}