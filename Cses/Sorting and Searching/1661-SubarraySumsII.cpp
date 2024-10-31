#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, x; cin >> n >> x;

  map<long long, int> m;
  
  long long a, sum = 0, tot = 0;
  m[0] = 1;
  while(n--){
    cin >> a;
    sum += a;

    tot += m[sum-x];
    
    m[sum]++;
  }

  cout << tot;
}