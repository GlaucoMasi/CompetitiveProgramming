#include <bits/stdc++.h>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int k, r;
vector<vector<int>> v, memo;

int f(int d, int cover){
  if(d == k) return 0;
  if(memo[d][cover] != -1) return memo[d][cover];

  int ans = 1e9;
  if(cover >= d && cover != 0) ans = min(ans, f(d+1, cover));

  for(auto i : v[d]){
    ans = min(ans, f(d+1, max(cover, i)) + 1);    
  }

  return memo[d][cover] = ans;
} 

int main() {
  fin >> k >> r;
  v.resize(k);
  memo.resize(k, vector<int>(k, -1));

  for(int i = 0; i < r; i++){
    int a, b; fin >> a >> b;
    v[a].push_back(b);
  }

  fout << f(0, 0);
}