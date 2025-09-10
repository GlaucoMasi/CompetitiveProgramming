#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  int n; cin >> n;
  vector<int> v(n);
  for(auto &i : v) cin >> i;

  int tot = 0, mx = 0;
  for(auto i : v) tot += i, mx = max(mx, i);

  vector<pair<int, int>> ans;
  priority_queue<pair<int, int>> pq;
  for(int i = 0; i < n; i++) if(v[i]) pq.push({v[i], i});
  while(!pq.empty()){
    int i = pq.top().second; pq.pop();

    vector<int> buffer;
    while(v[i]--){
      if(pq.empty()){
        cout << "IMPOSSIBLE";
        return 0;
      }

      int j = pq.top().second; pq.pop();
      buffer.push_back(j);
      ans.push_back({i+1, j+1});
    }

    for(auto j : buffer){
      v[j]--;
      pq.push({v[j], j});
    }
  }

  cout << ans.size() << '\n';
  for(auto [a, b] : ans) cout << a << " " << b << '\n';
}