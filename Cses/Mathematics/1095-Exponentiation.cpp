#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

long long MOD = 1e9+7;

int exp(long long a, long long b){
  if(b == 0) return 1;

  long long x = exp(a, b/2);
  x = (x * x) % MOD;

  if(b % 2 == 1) x = (x * a) % MOD;
  return x;
}

int main() {
  int n; cin >> n;

  for(int i = 0; i < n; i++){
    long long a, b; cin >> a >> b;
    cout << exp(a, b) << endl;
  }
}