#include <bits/stdc++.h>
using namespace std;
#define watch(x) cout << (#x) << " is " << (x) << endl
ifstream fin("input.txt");
ofstream fout("output.txt");
//fout << "Case #" << t << ": ";

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  
  int n, m; cin >> n >> m;
  vector<vector<int>> v(m, vector<int>(m, 1));

  for(int i = 0; i < n; i++){
    int k; cin >> k;
    vector<int> t(k);
    for(auto &i : t) cin >> i, i--;
    for(int a = 0; a < k; a++) for(int b = 0; b < k; b++) v[t[a]][t[b]] = 0;
  }

  vector<pair<int, int>> ans;
  for(int i = 0; i < m; i++) for(int j = i+1; j < m; j++) if(v[i][j]) ans.push_back({i+1, j+1});

  cout << ans.size() << '\n';
  for(auto [a, b] : ans) cout << a << " " << b << '\n';
}