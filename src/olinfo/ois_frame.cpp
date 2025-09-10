#include <bits/stdc++.h>
using namespace std;
#define watch(x) cout << (#x) << " is " << (x) << endl
ifstream fin("input.txt");
ofstream fout("output.txt");
//fout << "Case #" << t << ": ";

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  
  int ans = 0;
  long long n, m, a; cin >> n >> m >> a;

  auto check = [&](long long x, long long y){
    if(x < n || y < m) return 0;
    return 1;
  };

  for(long long i = 1; i*i <= a; i++){
    if(a%i) continue;
    long long x = i, y = a/i;
    if(x != y) ans += check(x, y)+check(y, x);
    else ans += check(x, y);
  }

  cout << ans;
}