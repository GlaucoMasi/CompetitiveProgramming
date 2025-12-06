#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;

  vector<string> grid;
  vector<pair<bool, int>> ops;
  while(getline(cin, s)) {
    if(min(s.find('*'), s.find('+')) == string::npos) grid.push_back(s);
    else {
      for(int i = 0; i < s.size(); i++) {
        if(s[i] == '*') ops.push_back({1, i});
        else if(s[i] == '+') ops.push_back({0, i});
      }
      ops.push_back({0, s.size()+1});
    }
  }

  long long ans = 0;
  for(int op = 0; op < ops.size()-1; op++) {
    long long temp = ops[op].first;

    for(int column = ops[op].second; column < ops[op+1].second-1; column++) {
      long long curr = 0;

      for(int row = 0; row < grid.size(); row++) {
        if(grid[row][column] != ' ') {
          curr *= 10;
          curr += grid[row][column] - '0';
        }
      }

      if(ops[op].first) temp *= curr;
      else temp += curr;
    }

    ans += temp;
  }

  cout << ans;
}