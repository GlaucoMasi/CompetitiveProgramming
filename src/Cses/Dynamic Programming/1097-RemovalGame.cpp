#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> v;
vector<vector<pair<long long, long long>>> ans;

int main() {
  cin >> n;
  v.resize(n);
  ans.resize(n, vector<pair<long long, long long>>(n));
  for(auto &i : v) cin >> i;

  for(int i = 0; i < n; i++) ans[i][i] = {v[i], 0};

  for(int k = 1; k < n; k++){
    for(int i = 0; i < n; i++){
      if(i + k >= n) continue;

      long long left = ans[i+1][i+k].second + v[i];
      long long right = ans[i][i+k-1].second + v[i+k];
      
      if(left > right){ 
        ans[i][i+k].first = left;
        ans[i][i+k].second = ans[i+1][i+k].first;
      }else{
        ans[i][i+k].first = right;
        ans[i][i+k].second = ans[i][i+k-1].first;
      }
    }
  }

  cout << ans[0][n-1].first;
}