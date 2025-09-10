#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  int n, m; cin >> n >> m;
  vector<vector<int>> v(n, vector<int>(m));
  for(auto &i : v) for(auto &j : i){
    char c; cin >> c;
    j = (c == '*');
  }

  long long best = 0;
  vector<long long> height(m, 0);
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      if(v[i][j]) height[j] = 0;
      else height[j]++;
    }

    vector<long long> left(m), right(m);
    stack<pair<int, int>> s; s.push({-1, -1});
    for(int j = 0; j < m; j++){
      while(!s.empty() && s.top().second >= height[j]) s.pop();
      left[j] = s.top().first;
      s.push({j, height[j]});
    }

    while(!s.empty()) s.pop(); s.push({m, -1});
    for(int j = m-1; j >= 0; j--){
      while(!s.empty() && s.top().second >= height[j]) s.pop();
      right[j] = s.top().first;
      s.push({j, height[j]});      
    }

    for(int j = 0; j < m; j++) best = max(best, height[j]*(right[j]-left[j]-1));
  }

  cout << best;
}