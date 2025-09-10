#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  int n; cin >> n;
  priority_queue<array<int, 3>> pq, nxt;
  for(int i = 0; i < n; i++){
    int a, b; cin >> a >> b;
    pq.push({a+b, i, b});
  }

  while(pq.size() > 1){
    int k = pq.size()/2;
    while(k--){
      auto [t, idx, b] = pq.top();
      nxt.push({t+b, idx, b});
      pq.pop();
    }

    while(!pq.empty()) pq.pop();
    swap(pq, nxt);
  }

  cout << pq.top()[1];
}