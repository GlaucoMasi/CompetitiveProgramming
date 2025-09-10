#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  int n, e, l; fin >> n >> e >> l;
  
  int all = 0;
  vector<int> lives(n, l);
  
  while(e--){
    int a; char c;
    fin >> a >> c;

    if(c == 'f'){
      int b; fin >> b;
      lives[b]--;
    }else{
      all--;
      lives[a]++;
    }
  }

  int alive = 0;
  for(int i = 0; i < n; i++) alive += (lives[i]+all) > 0;

  fout << alive;
}