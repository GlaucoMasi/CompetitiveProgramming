#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  int x, n; cin >> x >> n;
  priority_queue<int, vector<int>, greater<>> pq;
  for(int i = 0; i < n; i++){
    int a; cin >> a;
    pq.push(a);
  }

  long long ans = 0;
  while(pq.size() > 1){
    int a = pq.top(); pq.pop();
    int b = pq.top(); pq.pop();
    ans += a+b;
    pq.push(a+b);
  }
  
  cout << ans;
}