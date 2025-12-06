#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;

  vector<vector<long long>> grid;
  while(getline(cin, s)) {
    stringstream ss(s);
    
    string t;
    vector<long long> temp;
    while(ss >> t) {
      if(t == "+" || t == "*") temp.push_back(t == "*");
      else temp.push_back(stoi(t));
    }

    grid.push_back(temp);
  }

  long long ans = 0;
  for(int i = 0; i < grid[0].size(); i++) {
    long long temp = grid[grid.size()-1][i];
    for(int j = 0; j < grid.size()-1; j++) {
      if(grid[grid.size()-1][i]) temp *= grid[j][i];
      else temp += grid[j][i];
    }
    ans += temp;
  }

  cout << ans;
}