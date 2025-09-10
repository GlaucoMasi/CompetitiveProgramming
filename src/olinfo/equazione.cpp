#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  int64_t n; cin >> n;
  
  auto digitsum = [&](int64_t i){
    int ans = 0;
    while(i){
      ans += i%10;
      i /= 10;
    }
    return ans;
  };

  for(int sum = 0; sum <= 81; sum++){
    int64_t delta = sum*sum+4*n;
    if((int64_t)sqrt(delta)*(int64_t)sqrt(delta) != delta) continue;

    delta = sqrt(delta);

    int64_t x1 = (-sum-delta)/2, x2 = (-sum+delta)/2;

    if(digitsum(x1) == sum){
      cout << x1;
      return 0;
    }else if(digitsum(x2) == sum){
      cout << x2;
      return 0;
    }
  }

  cout << -1;
}