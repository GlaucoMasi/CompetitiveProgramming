#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
  int n, a, b; cin >> n >> a >> b;
  vector<long long> v(n); for(auto &i : v) cin >> i;
  for(int i = 1; i < n; i++) v[i] += v[i-1];

  long long best = -1e18;
  priority_queue<pair<long long, int>> pq;
  for(int i = 0; i < n; i++){
    if(i-a == -1) pq.push({0, -1});
    if(i-a >= 0) pq.push({-v[i-a], i-a}); 
    while(!pq.empty() && pq.top().second < i-b) pq.pop();
    if(!pq.empty()) best = max(best, v[i]+pq.top().first);
  }

  cout << best;
}