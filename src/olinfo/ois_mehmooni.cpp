#include <bits/stdc++.h>
using namespace std;

int main() {
  int n; cin >> n;

  int a, b;
  vector<pair<int, int>> v;
  for(int i = 0; i < n; i++){
    cin >> a >> b;
    v.push_back({a, 1});
    v.push_back({b, -1});
  }

  sort(v.begin(), v.end());

  int curr = 1; long long tot = 0;
  for(auto i : v){
    tot += curr - (i.second == -1);
    curr += i.second;
  }

  cout << tot;
}