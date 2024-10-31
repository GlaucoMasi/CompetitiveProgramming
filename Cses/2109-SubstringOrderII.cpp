#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int idx = 1;
long long k;
const int maxv = 3e5;

int nxt[maxv][26];
int lenght[maxv], back[maxv];
long long cnt[maxv], freq[maxv];

long long calc(int i){
  if(freq[i]) return freq[i];
  for(int j = 0; j < 26; j++) if(nxt[i][j]) freq[i] += calc(nxt[i][j]);
  return freq[i] += cnt[i];
}

string ans = "";
void f(int i){
  if(k < cnt[i]) return;
  k -= cnt[i];

  for(int j = 0; j < 26; j++){
    if(!nxt[i][j]) continue;
    
    if(freq[nxt[i][j]] > k){
      ans += ('a'+j);
      f(nxt[i][j]);
      return;
    }
    
    k -= freq[nxt[i][j]];
  }
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  string s;
  cin >> s >> k;

  int last = 0; back[0] = -1;
  for(auto ch : s){
    int c = ch-'a', i = last, curr = idx++;
    lenght[curr] = lenght[i]+1;
    cnt[curr] = 1;

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

        for(int j = 0; j < 26; j++) nxt[clone][j] = nxt[q][j];
        back[clone] = back[q];
        lenght[clone] = lenght[i]+1;

        while(i != -1 && nxt[i][c] == q){
          nxt[i][c] = clone;
          i = back[i];
        }

        back[q] = back[curr] = clone;
      }
    }

    last = curr;
  }

  vector<int> ord[idx];
  for(int i = 0; i < idx; i++) ord[lenght[i]].push_back(i);
  for(int i = idx-1; i >= 0; i--) for(auto j : ord[i]) if(back[j] != -1) cnt[back[j]] += cnt[j];
  cnt[0] = 1;

  calc(0);
  f(0);
  cout << ans;
}
