#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> v;

int f(int i, int last){
  if(i == n) return 1;
  if(v[i] != 0){ 
    if(abs(v[i]-last) > 1) return 0;
    else return f(i+1, v[i]);
  }

  int ans = 0;
  for(int k = max(1, last-1); k <= last+1 && k <= m; k++) ans += f(i+1, k);
  return ans;
}

int main() {
  cin >> n >> m;
  v.resize(n);
  for(auto &i : v) cin >> i;

  cout << f(0, v[0]);
}