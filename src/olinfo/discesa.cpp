#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int n;
vector<vector<int>> memo;
int pir[20][20] = {0};

int main() {
  fin.tie(0);
  fin.sync_with_stdio(0);

  fin >> n;

  memo.resize(20, vector<int>(20, 0));

  for(int i = 0; i < n; i++)
    for(int j = 0; j < i+1; j++)
      fin >> pir[i][j];

  for(int i = n-1; i >= 0; i--){
    for(int j = 0; j < i+1; j++){
      memo[i][j] = pir[i][j] + max(memo[i+1][j], memo[i+1][j+1]);
    }
  }

  fout << memo[0][0];
}