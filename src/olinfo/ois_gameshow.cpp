#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  vector<pair<int, int>> v(n);
  for(auto &i : v) cin >> i.first;
  for(auto &i : v) cin >> i.second;

  int tot = 0;
  for(auto &i : v){
    if(m >= i.first){
      m -= i.first;
      tot++;
    }else m += i.second;
  }

  cout << tot << " " << m;
}