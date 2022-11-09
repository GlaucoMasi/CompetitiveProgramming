#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> v;
vector<vector<int>> g;
vector<vector<long long>> memo;

void f(int i, int fat){
  if(g[i].size() == 1 && i != 0){
    memo[i][0] = 0;
    memo[i][1] = v[i];
    return;
  }

  long long ans = 0;
  int spenti = 0;
  long long diff = 1e16;
  for(auto j : g[i]){
    if(j == fat) continue;
    f(j, i);

    if(memo[j][0] > memo[j][1]){
      spenti++;
      ans += memo[j][0];
    }else ans += memo[j][1];

    diff = min(diff, abs(memo[j][0]-memo[j][1]));
  }

  if(spenti%2 == 0){
    memo[i][1] = ans+v[i];
    memo[i][0] = ans-diff;
  }
  else{
    memo[i][0] = ans;
    memo[i][1] = ans-diff+v[i];
  }
}

int main() {
  cin >> n;
  
  g.resize(n);
  int a, b;
  for(int i = 0; i < n-1; i++){
    cin >> a >> b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  
  v.resize(n); for(auto &i : v) cin >> i;

  memo.resize(n, vector<long long>(2));

  f(0, -1);

  cout << max(memo[0][0], memo[0][1]);
}