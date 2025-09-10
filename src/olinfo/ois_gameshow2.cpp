#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> prize(n), cost(n), comp(n);
  for(auto &i : prize) cin >> i;
  for(auto &i : cost) cin >> i;
  for(auto &i : comp) cin >> i;

  
  int start = 0, m = 0, tot = 0;
  for(int i = 0; i < n; i++){
    if(prize[i] - cost[i] > comp[i]){
      if(m < cost[i]){
        start += cost[i]-m;
        m = 0;
      }else{
        m -= cost[i];
      }

      tot += prize[i] - cost[i];
    }else{
      tot += comp[i];
      m += comp[i];
    }
  }

  cout << tot << " " << start;
}