#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  int n; cin >> n;
  vector<long double> v(n); for(auto &i : v) cin >> i;

  long double ans = 0;
  for(int i = 0; i < n; i++){
    long double temp = 0;
    for(int j = 1; j <= v[i]; j++) for(int k = i+1; k < n; k++) temp += min(v[k], (long double)j-1)/v[k];
    temp /= v[i];
    ans += temp;
  }

  ans *= 1e6;
  long double integ, fract = modf(ans, &integ);

  if(fract == 0.5){
    if(((long long)integ%10)%2) integ++;
  }else integ = round(ans);

  integ /= 1e6;
  cout << std::setprecision(6) << std::fixed << integ;
}