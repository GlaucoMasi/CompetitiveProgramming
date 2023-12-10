#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
  string a;
  vector<string> mat;

  while(getline(fin, a)) mat.push_back(a);

  int x, y;
  for(int i = 0; i < mat.size(); i++) for(int j = 0; j < mat[0].size(); j++) if(mat[i][j] == 'S'){
    x = i; y = j;
  }

  // prov:
  //    4
  // 1     3
  //    2

  queue<array<int, 4>> q;
  q.push({x, y, -1, 0});
  while(1){
    auto [a, b, prov, d] = q.front(); q.pop();

    if(a >= mat.size() || a < 0 || b >= mat[0].size() || b < 0) continue;
  
    if(a == x && b == y && d){
      fout << d/2 + d%2;
      break;
    }

    if(mat[a][b] == '|'){
      if(prov == 4) q.push({a+1, b, 4, d+1});
      else if(prov == 2) q.push({a-1, b, 2, d+1});
    }else if(mat[a][b] == '-'){
      if(prov == 1) q.push({a, b+1, 1, d+1});
      else if(prov == 3) q.push({a, b-1, 3, d+1});
    }else if(mat[a][b] == 'L'){
      if(prov == 4) q.push({a, b+1, 1, d+1});
      else if(prov == 3) q.push({a-1, b, 2, d+1});
    }else if(mat[a][b] == 'J'){
      if(prov == 4) q.push({a, b-1, 3, d+1});
      else if(prov == 1) q.push({a-1, b, 2, d+1});      
    }else if(mat[a][b] == '7'){
      if(prov == 2) q.push({a, b-1, 3, d+1});
      else if(prov == 1) q.push({a+1, b, 4, d+1});      
    }else if(mat[a][b] == 'F'){
      if(prov == 2) q.push({a, b+1, 1, d+1});
      else if(prov == 3) q.push({a+1, b, 4, d+1});
    }else if(mat[a][b] == 'S'){
      q.push({a+1, b, 4, d+1});
      q.push({a-1, b, 2, d+1});
      q.push({a, b+1, 1, d+1});
      q.push({a, b-1, 3, d+1});
    }
  }
}