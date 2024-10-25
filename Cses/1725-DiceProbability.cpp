#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  int n, a, b; cin >> n >> a >> b;
  vector<vector<double>> v(n+1, vector<double>(6*n+1)); v[0][0] = 1;
  for(int i = 1; i <= n; i++) for(int j = 1; j <= 6*n; j++) for(int k = 1; k <= min(j, 6); k++) v[i][j] += 1.0/6*v[i-1][j-k];
  
  double ans = 0;
  for(int i = a; i <= b; i++) ans += v[n][i];
  
  ans *= 1e6;
  double integ, fract = modf(ans, &integ);
 
  if(fract == 0.5){
    if(((long long)integ%10)%2) integ++;
  }else integ = round(ans);
 
  integ /= 1e6;
  cout << std::setprecision(6) << std::fixed << integ;
}