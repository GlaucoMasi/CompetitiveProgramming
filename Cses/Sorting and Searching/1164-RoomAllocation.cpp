#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  
  int n; cin >> n;
  vector<array<int, 3>> v(n);
  for(int i = 0; i < n; i++) cin >> v[i][0] >> v[i][1], v[i][2] = i;
  sort(v.begin(), v.end());

  vector<int> ans(n);
  priority_queue<int> free;
  priority_queue<pair<int, int>> leave;
  for(int i = 1; i <= n; i++) free.push(-i);
  for(auto [l, r, i] : v){
    while(!leave.empty() && -leave.top().first < l) free.push(leave.top().second), leave.pop();
    ans[i] = -free.top(); free.pop();
    leave.push({-r, -ans[i]});
  }

  cout << *max_element(ans.begin(), ans.end()) << '\n';
  for(auto i : ans) cout << i << " ";
}