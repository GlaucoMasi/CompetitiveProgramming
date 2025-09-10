#include <bits/stdc++.h>
using namespace std;

int n, m;
int mod = 1e9 + 7;
vector<vector<int>> ans;

void gen(int i, int mask, int next, vector<int> &list){
  if(i == n){
    list.push_back(next);
    return;
  }

  if((mask&(1<<i)) == 0){
    if((mask&(1<<(i+1))) == 0 && i+1 < n) gen(i+2, mask, next, list);

    gen(i+1, mask, next + (1<<i), list);
  }else gen(i+1, mask, next, list);
}

int f(int i, int mask){
  if(i == m) return (mask == 0);

  if(ans[i][mask] != -1) return ans[i][mask];

  int tot = 0;
  vector<int> list;
  gen(0, mask, 0, list);

  for(auto j : list){
    tot = (tot + f(i+1, j)) % mod;
  }

  return ans[i][mask] = tot;
}

int main() {
  cin >> n >> m;
  ans.resize(m, vector<int>(1<<n, -1));
  cout << f(0, 0);
}