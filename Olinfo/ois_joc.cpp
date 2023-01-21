#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k; cin >> n >> k;
  int goal = (1<<(k-1));

  int a, start = 0;
  for(int i = 0; i < n; i++){
    cin >> a;
    if(a) start |= (1<<i);
  }

  vector<int> upd(n, (1<<n)-1);
  for(int i = 0; i < n; i++){
    int t; cin >> t;

    while(t--){
      cin >> a;
      upd[i] ^= (1<<(a-1));
    }
  }

  vector<bool> memo(1<<n);
  queue<pair<int, int>> q;
  q.push({start, 0});
  while(!q.empty()){
    int curr = q.front().first, d = q.front().second; q.pop();
    if(memo[curr]) continue;
    memo[curr] = 1;

    if(curr == goal){
      cout << d;
      break;
    }

    for(int i = 0; i < n; i++){
      if(curr & (1<<i)) continue;

      int next = curr & upd[i];
      next |= (1<<i);
      q.push({next, d+1});
    }
  }
}