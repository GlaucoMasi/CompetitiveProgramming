#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

double exp(double a, int b){
  if(b == 0) return 1;
  if(b == 1) return a;

  double ans = exp(a, b/2);
  ans *= ans;
  if(b%2) ans *= a;

  return ans;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  
  double ans = 0;
  int n, k; cin >> n >> k;
  for(double i = 1; i <= k; i++) ans += i*(exp(i*1.0/k, n)-exp((i-1)*1.0/k, n));

  ans *= 1e6;
  double integ, fract = modf(ans, &integ);

  if(fract == 0.5){
    if(((long long)integ%10)%2) integ++;
  }else integ = round(ans);

  integ /= 1e6;
  cout << std::setprecision(6) << std::fixed << integ;
}