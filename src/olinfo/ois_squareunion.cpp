#include <bits/stdc++.h>
using namespace std;

int main() {
  int n; cin >> n;
  vector<int> x(n), r(n);
  for(auto &i : x) cin >> i;
  for(auto &i : r) cin >> i;

  vector<int> points;
  map<int, vector<int>> upd;
  for(int i = 0; i < n; i++){
    points.push_back(x[i]-r[i]);
    points.push_back(x[i]+r[i]);
    upd[x[i]-r[i]].push_back(i);
  }

  long long ans = 0; priority_queue<pair<long long, int>> pq;
  sort(points.begin(), points.end()); points.resize(unique(points.begin(), points.end())-points.begin());
  for(int i = 0; i < points.size()-1; i++){
    for(auto j : upd[points[i]]) pq.push({2*r[j], x[j]+r[j]});
    while(!pq.empty() && pq.top().second <= points[i]) pq.pop();

    if(!pq.empty()) ans += (long long)(points[i+1]-points[i])*pq.top().first;
  }

  cout << ans;
}