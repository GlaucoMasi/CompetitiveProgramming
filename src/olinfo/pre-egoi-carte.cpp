#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int scarta(int M, vector<bool> L, vector<bool> D, vector<bool> N){
  int ans = M;
  
  for(int i = 0; i < M; i++){
    if(L[i]+D[i]+N[i] == 1) ans--;
  }
  
  return ans;
}