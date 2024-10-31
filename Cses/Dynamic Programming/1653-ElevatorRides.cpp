#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, x; cin >> n >> x;
  vector<int> v(n);
  for(auto &i : v) cin >> i;
  vector<pair<int, int>> ans(1<<n);
  ans[0] = {1, 0};

  for(int i = 1; i < (1<<n); i++){
    ans[i] = {n+1, 0};

    for(int j = 0; j < n; j++){
      if(i&(1<<j)){
        auto best = ans[i^(1<<j)];

        if(best.second + v[j] <= x){
          best.second += v[j];
        }else{
          best.first++;
          best.second = v[j];
        }

        ans[i] = min(ans[i], best);
      }
    }
  }

  cout << ans[(1<<n)-1].first;
}