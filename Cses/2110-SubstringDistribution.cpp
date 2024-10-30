#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int idx = 1;
const int maxv = 3e5;

int nxt[maxv][26];
int back[maxv], lenght[maxv];

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  back[0] = -1;
  int last = 0;
  string s; cin >> s;
  for(auto ch : s){
    int c = ch-'a';

    int i = last, curr = idx++;
    lenght[curr] = lenght[last]+1;

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

        back[clone] = back[q];
        for(int k = 0; k < 26; k++) nxt[clone][k] = nxt[q][k];
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

  vector<long long> add(s.size()+1);
  for(int i = 1; i < idx; i++){
    add[lenght[back[i]]]++;
    add[lenght[i]]--;
  }

  long long curr = add[0];
  for(int i = 1; i <= s.size(); i++){
    cout << curr << " ";
    curr += add[i];
  }
}