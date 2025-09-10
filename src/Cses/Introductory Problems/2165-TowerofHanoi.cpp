#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  int n; cin >> n;
  vector<stack<int>> v(3);
  queue<pair<int, int>> q;
  if(n%2){
    q.push({0, 2});
    q.push({0, 1});
    q.push({1, 2});
  }else{
    q.push({0, 1});
    q.push({0, 2});
    q.push({1, 2});
  }

  for(int i = 16; i >= 1; i--) v[0].push(i);

  cout << (1<<n)-1 << '\n';
  while(v[2].size() != n){
    auto [i, j] = q.front(); q.push(q.front()); q.pop();
    if(v[i].empty() || (!v[j].empty() && v[j].top() < v[i].top())) swap(i, j);
    cout << i+1 << " " << j+1 << '\n';
    v[j].push(v[i].top());
    v[i].pop();
  }
}