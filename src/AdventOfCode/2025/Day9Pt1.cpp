#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  vector<array<int, 2>> v;
  while(cin >> s) {
    int idx = s.find(',');
    v.push_back({
      stoi(s.substr(0, idx)),
      stoi(s.substr(idx+1))
    });
  }

  long long best = 0;
  for(int i = 0; i < v.size(); i++) {
    for(int j = i+1; j < v.size(); j++) {
      best = max(best, 1LL*(abs(v[j][0]-v[i][0])+1)*(abs(v[j][1]-v[i][1])+1));
    }
  }

  cout << best;
}