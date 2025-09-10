#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  long long n; cin >> n; n++;
  long long p = 1, ans = 0;
  while(p <= n){
    long long num = n/(2LL*p);
    ans += num*p;
    long long off = n-num*2LL*p;
    ans += max(0LL, off-p);
    p *= 2LL;
  }

  cout << ans << '\n';
}