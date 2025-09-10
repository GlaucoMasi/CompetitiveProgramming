#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

void solve() {
  int n; cin >> n;
  vector<int> a(n), b(n-1);
  for(auto &i : a) cin >> i;
  for(auto &i : b) cin >> i;

  int l = 0, r = 2e9+1;
  while(l < r-1){
    int m = l + (r-l)/2;

    bool fail = 0;
    vector<int> tempa = a, tempb = b;
    for(int i = 0; i < n; i++){
      if(i) tempa[i] += tempb[i-1];
      if(tempa[i] >= m) continue;
      if(i != n-1 && tempb[i] >= m-tempa[i]){
        tempb[i] -= m-tempa[i];
        continue;
      }

      fail = 1;
      break;
    }

    if(fail) r = m;
    else l = m;
  }

  cout << l << '\n';
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int t; cin >> t;
  while(t--) solve();
}