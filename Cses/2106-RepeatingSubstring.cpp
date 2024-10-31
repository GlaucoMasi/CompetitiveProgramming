#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int idx = 1;
const int maxv = 3e6;

int nxt[maxv][26];
int back[maxv], lenght[maxv], firstpos[maxv], cnt[maxv];

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  string s; cin >> s;

  int last = 0; back[0] = -1;
  for(int j = 0; j < s.size(); j++){
    int c = s[j]-'a', i = last, curr = idx++;
    lenght[curr] = lenght[i]+1;
    firstpos[curr] = j;
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

        for(int k = 0; k < 26; k++) nxt[clone][k] = nxt[q][k];
        back[clone] = back[q];
        firstpos[clone] = firstpos[q];
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

  vector<int> cntsort[idx];
  for(int i = 0; i < idx; i++) cntsort[lenght[i]].push_back(i);
  for(int i = idx-1; i >= 0; i--) for(auto j : cntsort[i]) if(back[j] != -1) cnt[back[j]] += cnt[j];

  pair<int, int> best; best.first = -1;
  for(int i = 1; i < idx; i++) if(cnt[i] > 1) best = max(best, {lenght[i], firstpos[i]-lenght[i]+1});

  if(best.first == -1) cout << -1;
  else cout << s.substr(best.second, best.first);
}
