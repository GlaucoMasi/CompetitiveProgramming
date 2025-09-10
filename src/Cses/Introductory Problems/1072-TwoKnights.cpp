#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

long long solve(long long n){
  if(n == 1) return 0;
  if(n == 2) return 6;
  if(n == 3) return 28;
  if(n == 4) return 96;

  long long ans = 0;
  ans += 4LL*(n-4)*(n-2);
  ans += 2LL*(n-4);
  ans += 3LL*2LL*(n-2);
  ans += 2LL*2LL*(n-2);
  ans += 4LL;
  return n*n*(n*n-1)/2-ans;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  int n; cin >> n;
  for(int i = 1; i <= n; i++) cout << solve(i) << '\n';
}