#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, x;
  cin >> n >> x;

  vector<int> v;
  vector<int> memo(1e7, 1e9);
  for(int i = 0; i < n; i++){
    int a; cin >> a;
    
    if(a <= x) v.push_back(a);

    memo[a] = 1;
  }


  for(int i = 0; i < v.size(); i++){
    int c = v[i];

    for(int j = c; j <= x; j++){
      memo[j] = min(memo[j - c] + 1, memo[j]);
    }
  }

  int ans = (memo[x] < 1e9) ? memo[x] : -1;
  cout << ans;
}