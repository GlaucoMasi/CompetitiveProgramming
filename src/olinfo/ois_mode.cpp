#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  
  int n; cin >> n;

  map<int, int> m;
  unordered_set<int> been;
  int mode = 0;
  while(n--){
    int a; cin >> a;
    mode = max(mode, ++m[a]);
    if(m[a] == mode) been.insert(a);
  }

  cout << been.size();
}