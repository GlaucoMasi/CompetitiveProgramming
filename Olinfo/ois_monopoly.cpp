#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<int> tax;
vector<vector<vector<long long>>> memo;

long long f(int i, int turns, int moves){
  if(!turns) return 0;
  if(memo[i][turns][moves] != -1) return memo[i][turns][moves];

  long long best = -1e18;

  for(int k1 = 1; k1 <= 6; k1++){
    for(int k2 = 1; k2 <= 6; k2++){
      long long curr = tax[(i+k1+k2)%n];

      if(k1 == k2 && moves < 2) curr += f((i+k1+k2)%n, turns, moves+1);
      else curr += f((i+k1+k2)%n, turns-1, 0);

      best = max(best, curr);
    }
  }

  return memo[i][turns][moves] = best;
}

int main() {
  cin >> n >> k;
  tax.resize(n); memo.resize(n, vector<vector<long long>>(k+1, vector<long long>(3, -1)));
  for(auto &i : tax) cin >> i;

  cout << f(0, k, 0);
}