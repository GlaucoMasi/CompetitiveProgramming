#include <bits/stdc++.h>
using namespace std;

bool solve() {
  int n; cin >> n;
  
  vector<int> dig;
  while(n > 0){
    dig.push_back(n%10);
    n /= 10;
  }

  if(dig.size() <= 2) return 0;
  if(dig[dig.size()-1] != 1 || dig[dig.size()-2] != 0) return 0;
  if(dig[dig.size()-3] == 0 || (dig[dig.size()-3] == 1 && dig.size() == 3)) return 0;
  return 1;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int t = 1;
  cin >> t;
  while(t--) cout << (solve() ? "YES" : "NO") << '\n';
}