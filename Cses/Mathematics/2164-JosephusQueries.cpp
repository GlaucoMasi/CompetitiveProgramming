#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int solve(int n, int k){
  if(n == 1) return 1;
  if(k <= (n+1)/2) return (2*k > n ? (2*k)%n : 2*k);
  return 2*solve(n/2, k-(n+1)/2) + (n%2 ? 1 : -1);
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  int t; cin >> t;
  while(t--){
    int a, b; cin >> a >> b;
    cout << solve(a, b) << '\n';
  }
}