#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m, r, g, b; cin >> n >> m >> r >> g >> b;

  if(max({r, g, b}) > (n*m+1)/2) cout << "NO\n";
  else{
    vector<pair<int, int>> v = {{r, 0}, {g, 1}, {b, 2}};
    sort(v.begin(), v.end(), greater<>());

    vector<vector<int>> ans(n, vector<int>(m));

    for(int i = 0; i <= n+m-2; i += 2){
      for(int j = min(i, n-1); j >= 0 && i-j < m; j--){
        if(v[0].first){
          ans[j][i-j] = v[0].second;
          v[0].first--;
        }else{
          ans[j][i-j] = v[1].second;
          v[1].first--;
        }
      }
    }

    for(int i = 1; i <= n+m-2; i += 2){
      for(int j = min(i, n-1); j >= 0 && i-j < m; j--){
        if(v[1].first){
          ans[j][i-j] = v[1].second;
          v[1].first--;
        }else{
          ans[j][i-j] = v[2].second;
          v[2].first--;
        }
      }
    }

    cout << "YES\n";
    vector<char> t = {'R', 'G', 'B'};

    for(auto i : ans){
      for(auto j : i) cout << t[j];
      cout << '\n';
    }
  }
}