#include <bits/stdc++.h>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int r, c;
int tot = 0;
vector<vector<int>> v, status;

int check(int x, int y, bool conto){
  if(status[x][y] == 2) return false;
  if(v[x][y] == -1) return false;
  if(status[x][y] == -1) return false;
  if(status[x][y] == 1) return true;

  status[x][y] = 2;
  int temp = -1;
  if(check(x+1, y, 0) == 1) temp = 1;
  if(check(x-1, y, 0) == 1) temp = 1;
  if(check(x, y+1, 0) == 1) temp = 1;
  if(check(x, y-1, 0) == 1) temp = 1;
  
  status[x][y] = temp;
  if(conto && temp == -1) tot++;
  return temp;
}

int main() {
  fin >> r >> c;
  v.resize(r, vector<int>(c));
  status.resize(r, vector<int>(c, 0));

  for(int i = 0; i < r; i++)
    for(int j = 0; j < c; j++){
      char c; fin >> c;

      if(c == '#') v[i][j] = -1;
      else if(c == '.') v[i][j] = 0;
      else{ 
        v[i][j] = status[i][j] = 1;
      }
    }

  for(int i = 0; i < r; i++)
    for(int j = 0; j < c; j++)
      check(i, j, 1);

  fout << tot;
}