#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m; cin >> n >> m;
  vector<int> v(n+1, 0); v[n] = 1e9;

  int a, b;
  while(m--){
    cin >> a >> b;
    v[a-1]++; v[b]--;
  }

  int curr = 0;
  for(int i = 0; i < n; i++){
    curr += v[i];
    v[i] = curr;
  }

  nth_element(v.begin(), v.begin()+n/2, v.end());
  cout << v[n/2];
}