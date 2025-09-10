#include <bits/stdc++.h>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int n, q;
int best = 0;
vector<vector<int>> v;

void check(vector<int> &a, vector<int> &b){
  int ans = 0;

  for(int i = 0; i < q; i++){
    if(a[i] != b[i]) break;

    ans++;
  }

  best = max(best, ans);
  return;
}

int main(){
  fin >> n >> q;
  v.resize(n, vector<int>(q));
  
  for(int i = 0; i < n; i++){
    for(int j = 0; j < q; j++) fin >> v[i][j];
  }

  for(int i = 0; i < n; i++){
    for(int j = i+1; j < n; j++) check(v[i], v[j]);
  }

  fout << best;
}