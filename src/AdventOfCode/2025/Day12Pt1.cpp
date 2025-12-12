#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  vector<int> area(6);
  for(int i = 0; i < 6; i++) {
    cin >> s;
    for(int j = 0; j < 3; j++) {
      cin >> s;
      for(auto c : s) area[i] += (c == '#');
    }
  }

  int ans = 0;
  while(cin >> s) {
    int idx = s.find('x');
    int totalArea = stoi(s.substr(0, idx))*stoi(s.substr(idx+1));
    
    for(int i = 0; i < 6; i++) {
      int k; cin >> k;
      totalArea -= area[i]*k;
    }

    ans += (totalArea >= 0);
  }

  cout << ans;
}