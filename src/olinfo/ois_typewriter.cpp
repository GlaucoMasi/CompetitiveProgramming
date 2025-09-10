#include <bits/stdc++.h>
using namespace std;

vector<string> str(3);
vector<vector<pair<int, int>>> v(3);

bool test() {
  if(v[0].size() != v[1].size() || v[0].size() != v[2].size() || v[1].size() != v[2].size()) return 0;

  for(int i = 0; i < v[0].size(); i++){
    if(v[0][i].first != v[1][i].first || v[0][i].first != v[2][i].first || v[1][i].first != v[2][i].first) return 0;
  }

  vector<pair<int, int>> ans;
  for(int i = 0; i < v[0].size(); i++){
    vector<int> t = {v[0][i].second, v[1][i].second, v[2][i].second};
    sort(t.begin(), t.end());

    ans.push_back({v[0][i].first, t[1]});
  }

  for(auto [c, t] : ans) for(int i = 0; i < t; i++) cout << (char)(c);
  return 1;
}

int main() {
  for(auto &i : str) cin >> i;

  for(int i = 0; i < 3; i++){
    int count = 1;
    for(int j = 0; j < str[i].size(); j++){
      if(j+1 == str[i].size() || str[i][j] != str[i][j+1]){ 
        v[i].push_back({str[i][j], count}); count = 1;
      }else count++;
    }
  }
  
  if(!test()) cout << "IMPOSSIBLE";  
}