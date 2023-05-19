#include <bits/stdc++.h>
using namespace std;

int n;
vector<pair<int, int>> v;

int main() {
  cin >> n;
  v.resize(n);

  for(int i = 0; i < n; i++) cin >> v[i].first >> v[i].second;

  vector<bool> taken(n); taken[0] = 1;
  int i = 0;

  while(1){
    cout << i+1 << " ";
    pair<long long, int> ans = {-5e18, -1};

    for(int j = 0; j < n; j++){
      if(taken[j]) continue;

      long long x = v[i].first-v[j].first, y = v[i].second-v[j].second;
      long long dist = x*x + y*y;
      ans = max(ans, {dist, j});
    }
   
    if(ans.second == -1) break;
    i = ans.second;
    taken[i] = 1;
  }
}