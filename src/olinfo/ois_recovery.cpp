#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  multiset<vector<int>> ms;
  int t, s, q; cin >> t >> s >> q;

  for(int i = 0; i < t; i++){
    vector<int> curr(q);
    for(auto &i : curr) cin >> i;
    sort(curr.begin(), curr.end());
    ms.insert(curr);
  }

  int ans = 0;
  for(int i = 0; i < s; i++){
    vector<int> curr(q);
    for(auto &i : curr) cin >> i;
    sort(curr.begin(), curr.end());
    ans += ms.count(curr);
  }

  cout << ans;
}