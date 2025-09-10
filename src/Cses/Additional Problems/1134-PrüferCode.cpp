#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  int n; cin >> n;
  vector<int> v(n-2); for(auto &i : v) cin >> i;

  vector<int> idx(n+1, -1);
  for(int i = 0; i < n-2; i++) idx[v[i]] = i;

  priority_queue<int, vector<int>, greater<>> pq;
  for(int i = 1; i <= n; i++) if(idx[i] == -1) pq.push(i);

  for(int i = 0; i < n-2; i++){
    cout << pq.top() << " " << v[i] << '\n'; pq.pop();
    if(idx[v[i]] == i) pq.push(v[i]);
  }

  int a = pq.top(); pq.pop();
  cout << a << " " << pq.top();
}