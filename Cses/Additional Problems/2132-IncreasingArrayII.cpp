#include <bits/stdc++.h>
using namespace std;

int main() {
  int n; long long start = 0; cin >> n;
  vector<long long> v(n); for(auto &i : v) cin >> i, start += i;

  priority_queue<long long> pq; pq.push(0);
  for(int i = 0; i < n; i++){
    pq.push(v[i]); pq.push(v[i]);
    pq.pop();
  }

  long long last = 1e18;
  for(long long slope = 0; !pq.empty(); slope++){
    long long curr = pq.top(); pq.pop();
    start -= (slope*(last-curr));
    last = curr;
  }

  cout << start;
}