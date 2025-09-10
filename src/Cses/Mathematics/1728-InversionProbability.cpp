#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

/*
Python version for precision issues:
from decimal import Decimal, getcontext, ROUND_HALF_EVEN
getcontext().prec = 50

def sum(i):
    return i*(i-1)//2;

def main():
    n = int(input().strip())
    v = list(map(Decimal, input().split()))
    
    ans = Decimal(0)
    
    for j in range(n):
        for i in range(j):
            curr = Decimal(0)
            curr += sum(Decimal(v[i]))-sum(Decimal(v[i]-min(v[i], v[j])))
            ans += curr/(v[i]*v[j])
    
    ans = ans.quantize(Decimal("0.000000"), rounding=ROUND_HALF_EVEN)
    print(ans)

if __name__ == "__main__":
    main()
*/

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
