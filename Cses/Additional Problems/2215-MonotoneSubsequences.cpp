#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

void solve() {
  int n, k; cin >> n >> k;
  if(k*k < n) cout << "IMPOSSIBLE\n";
  else{
    for(int i = k; i-k <= n; i += k) for(int j = i; j > i-k; j--) if(j <= n) cout << j << " ";
    cout << '\n';
  }
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int t; cin >> t; while(t--) solve();
}