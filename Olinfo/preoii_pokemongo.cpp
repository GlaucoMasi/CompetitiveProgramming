#include <bits/stdc++.h>
using namespace std;

int num, lifes, ans = 0;
vector<vector<int>> memo;

void init(int n, int k){
  num = n; lifes = k;
  memo.resize(n+1, vector<int>(k+1));
  for(int i = 1; i <= n; i++) for(int j = 1; j <= k; j++) memo[i][j] = 1+memo[i-1][j-1]+memo[i-1][j];
  while(memo[ans][lifes] < num) ans++;
}

bool attack(int p);

int new_pokemon(){
  int off = 0, pok = num, left = lifes;
  
  for(int i = ans; i > 0 && pok; i--){
    int cover = min(pok, memo[i-1][left-1]+1);
    bool res = attack(off+cover-1);
    if(res){
      off += cover;
      pok -= cover;
    }else{
      left--;
      pok = cover-1;
    }
  }

  return off;
}