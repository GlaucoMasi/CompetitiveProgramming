#include <bits/stdc++.h>
using namespace std;

int main() {
  int n; cin >> n;
  vector<int> v(n);
  for(auto &i : v) cin >> i;

  vector<bool> ans(1e5+10);
  ans[0] = 1;
  int tot = 0;
  for(auto i : v){
    for(int j = 1e5+5; j >= i; j--){
      if(j-i < 0) continue;
      if(ans[j-i] && !ans[j]){ 
        ans[j] = 1;
        tot++;
      }
    }
  }

  cout << tot << endl;
  for(int i = 1; i < ans.size(); i++)
    if(ans[i]) cout << i << " ";
}