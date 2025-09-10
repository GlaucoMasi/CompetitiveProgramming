#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");
 
int exp(long long a, long long b, long long MOD){
  if(b == 0) return 1;
 
  long long x = exp(a, b/2, MOD);
  x = (x * x) % MOD;
 
  if(b % 2 == 1) x = (x * a) % MOD;
  return x;
}
 
int main() {
  int n; cin >> n;
 
  for(int i = 0; i < n; i++){
    long long a, b, c; cin >> a >> b >> c;
    long long t = exp(b, c, 1e9+6);
    cout << exp(a, t, 1e9+7) << endl;
  }
}