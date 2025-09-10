#include <bits/stdc++.h>
using namespace std;

long long compute(long long n){
  long long ans = 0;

  int tot = 0;
  long long d = 1;
  while(d <= n){
    long long m = n/d, r = n%d;
    ans += (r/m+1)*m;
    d += r/m+1;
  }

  return ans;
}