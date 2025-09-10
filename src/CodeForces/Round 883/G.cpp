#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, m;
  cin >> n >> m;

  string t; cin >> t;
  int start = 0;
  for(int i = 0; i < n; i++) start += (t[i]-'0')*(1<<i);

  vector<array<int, 3>> meds(m, {0, 0, 0});
  for(int i = 0; i < m; i++){
    string a, b;
    cin >> meds[i][0] >> a >> b;
    for(int j = 0; j < n; j++){
      meds[i][1] += ((a[j]-'0')^1)*(1<<j);
      meds[i][2] += (b[j]-'0')*(1<<j);
    }
  }

  vector<bool> prop(1<<n);
  vector<int> dist(1<<n, 1e9);
  priority_queue<pair<int, int>> pq;
  pq.push({0, start}); dist[start] = 0;
  while(!pq.empty()){
    int mask = pq.top().second; pq.pop();

    if(mask == 0) break;

    if(prop[mask]) continue;
    prop[mask] = 1;

    for(auto [time, cure, side] : meds){
      int next = mask&cure|side;

      if(dist[next] > dist[mask]+time){
        dist[next] = dist[mask]+time;
        pq.push({-dist[next], next});
      }
    }
  }

  cout << (dist[0] == 1e9 ? -1 : dist[0]) << '\n';
}

int main() {
  int t; cin >> t;
  while(t--) solve();
}