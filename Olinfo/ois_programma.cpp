#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int n, m;
string p;

vector<array<int, 3>> v;
vector<int> explode;

int main() {
  fin >> n >> m >> p;
  v.resize(n+1);

  v[0] = {0, 0, 1};
  for(int i = 0; i < n; i++){
    v[i+1] = v[i];

    if(p[i] == 'R') v[i+1][2] = (v[i+1][2]+1)%4;
    if(p[i] == 'L') v[i+1][2] = (v[i+1][2]+3)%4;
    
    if(p[i] == 'F' || p[i] == 'B'){
      int off = (p[i] == 'F' ? 1 : -1);

      if(v[i+1][2] == 0) v[i+1][1] += off;
      if(v[i+1][2] == 1) v[i+1][0] += off;
      if(v[i+1][2] == 2) v[i+1][1] -= off;
      if(v[i+1][2] == 3) v[i+1][0] -= off;
    }

    if(p[i] == 'X') explode.push_back(i+1);
  }

  int i, j;
  int x, y, r; 
  x = y = 0; r = 1;
  while(m--){
    fin >> i >> j; j++;

    auto t = upper_bound(explode.begin(), explode.end(), i);
    
    bool expl = 0;
    if(t != explode.end() && *t <= j){
      j = *t-1;
      expl = 1;
    }

    array<int, 3> ans;
    for(int k = 0; k < 3; k++) ans[k] = v[j][k] - v[i][k];
    int prev = v[i][2];

    if(prev == r){
      x += ans[0];
      y += ans[1];
    }else if(prev == (r+1)%4){
      x -= ans[1];
      y += ans[0];
    }else if(prev == (r+2)%4){
      x -= ans[0];
      y -= ans[1];
    }else{
      x += ans[1];
      y -= ans[0];
    }

    r = (r+ans[2])%4; r = (r+4)%4;
    if(expl) break;
  }

  fout << x << " " << y;
}