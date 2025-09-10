#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

const int MAX_X = 1e3;

vector<int> w;
vector<vector<int>> memo;

int f(int i, int last){
 
  if(i == w.size()-1){
    if(w[i] >= last && last != w[i-1]) return 1;
    else return 0;
  }else if(i == w.size()) return 0;

  if(memo[i][last] != -1) return memo[i][last];

  int prendo = (w[i] >= last) ? (1 + f(i + 2, w[i])) : 0;
  int non_prendo = f(i + 1, last);

  return memo[i][last] = max(prendo, non_prendo);
}

int main() {

  int n;
  fin >> n;

  w.resize(n);
  memo.resize(MAX_X+1, vector<int>(MAX_X+1, -1));

  for(int i = 0; i < n; i++)
    fin >> w[i];

  fout << f(0, 0);
}