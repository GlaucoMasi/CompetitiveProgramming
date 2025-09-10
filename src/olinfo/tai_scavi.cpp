#include <bits/stdc++.h>
using namespace std;

void scavi(int r, int c, int q, vector<int> &x1, vector<int> &y1,
vector<int> &x2, vector<int> &y2, vector<int> &p, vector<vector<int>> &terreno){
  for(int i = 0; i < q; i++){
    terreno[x1[i]][y1[i]] += p[i];
    if(x2[i]+1 < r) terreno[x2[i]+1][y1[i]] -= p[i];
    if(y2[i]+1 < c) terreno[x1[i]][y2[i]+1] -= p[i];
    if(x2[i]+1 < r && y2[i]+1 < c) terreno[x2[i]+1][y2[i]+1] += p[i];
  }

  for(int j = 0; j < c; j++){
    int curr = 0;
    
    for(int i = 0; i < r; i++){
      curr += terreno[i][j];
      terreno[i][j] = curr;
    }
  }

  for(int i = 0; i < r; i++){
    int curr = 0;
    
    for(int j = 0; j < c; j++){
      curr += terreno[i][j];
      terreno[i][j] = curr;
    }
  }
}