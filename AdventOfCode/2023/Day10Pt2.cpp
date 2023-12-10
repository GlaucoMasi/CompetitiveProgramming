#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int x, y;
vector<string> mat;
vector<vector<int>> memo;

bool f(int a, int b, int prov){
  if(a >= mat.size() || a < 0 || b >= mat[0].size() || b < 0) return 0;
  if(a == x && b == y && prov != -1) return memo[a][b] = 1;

  if(mat[a][b] == '|'){
    if(prov == 4) memo[a][b] = f(a+1, b, 4);
    else if(prov == 2) memo[a][b] = f(a-1, b, 2);
  }else if(mat[a][b] == '-'){
    if(prov == 1) memo[a][b] = f(a, b+1, 1);
    else if(prov == 3) memo[a][b] = f(a, b-1, 3);
  }else if(mat[a][b] == 'L'){
    if(prov == 4) memo[a][b] = f(a, b+1, 1);
    else if(prov == 3) memo[a][b] = f(a-1, b, 2);
  }else if(mat[a][b] == 'J'){
    if(prov == 4) memo[a][b] = f(a, b-1, 3);
    else if(prov == 1) memo[a][b] = f(a-1, b, 2);      
  }else if(mat[a][b] == '7'){
    if(prov == 2) memo[a][b] = f(a, b-1, 3);
    else if(prov == 1) memo[a][b] = f(a+1, b, 4);      
  }else if(mat[a][b] == 'F'){
    if(prov == 2) memo[a][b] = f(a, b+1, 1);
    else if(prov == 3) memo[a][b] = f(a+1, b, 4);
  }else if(mat[a][b] == 'S'){
    memo[a][b] = f(a+1, b, 4);
    memo[a][b] = f(a-1, b, 2);
    memo[a][b] = f(a, b+1, 1);
    memo[a][b] = f(a, b-1, 3);
  }

  return memo[a][b];
}

int main() {
  string a;

  while(getline(fin, a)) mat.push_back(a);

  for(int i = 0; i < mat.size(); i++) for(int j = 0; j < mat[0].size(); j++) if(mat[i][j] == 'S'){
    x = i; y = j;
  }

  // prov:
  //    4
  // 1     3
  //    2

  memo.resize(mat.size(), vector<int>(mat[0].size()));
  f(x, y, -1); memo[x][y] = 1;

  int count1 = 0, count2 = 0, tot = 0;
  for(int i = 0; i < mat.size(); i++){
    for(int j = 0; j < mat[0].size(); j++){
      if(memo[i][j] == 1) continue;

      count1 = 0; count2 = 0;
      for(int k1 = 0; k1 < j; k1++) if(memo[i][k1] == 1 && (mat[i][k1] == '|' || mat[i][k1] == 'J' || mat[i][k1] == 'L')) count1++;
      for(int k1 = 0; k1 < i; k1++) if(memo[k1][j] == 1 && (mat[k1][j] == '-' || mat[k1][j] == 'F' || mat[k1][j] == 'L')) count2++;

      if(count1%2 && count2%2) tot++;
    }
  }

  fout << tot;
}