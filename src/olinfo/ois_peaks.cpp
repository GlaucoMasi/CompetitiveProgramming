#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m; cin >> n >> m;
  vector<int> a(n), b(m);
  for(auto &i : a) cin >> i;
  for(auto &i : b) cin >> i;

  long long t1 = 0, t2 = 0;
  for(int i = 0; i < n; i++) t1 += ((i == 0 || a[i] > a[i-1]) && (i == n-1 || a[i] > a[i+1]));
  for(int i = 0; i < m; i++) t2 += ((i == 0 || b[i] > b[i-1]) && (i == m-1 || b[i] > b[i+1]));
  cout << t1*t2;
}