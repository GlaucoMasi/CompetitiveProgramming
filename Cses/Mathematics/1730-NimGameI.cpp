#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

void solve() {
  int n, t = 0; cin >> n;
  
  while(n--){
    int a; cin >> a;
    t ^= a;
  }

  if(t == 0) cout << "second\n";
  else cout << "first\n";
}

int main() {
  int t; cin >> t;
  while(t--) solve();
}