#include <bits/stdc++.h>
using namespace std;

int main() {
  long long n; cin >> n;
  vector<string> v(n); for(auto &i : v) cin >> i;
  long long b, p, d2, d3, d5, d7;
  cin >> b >> p >> d2 >> d3 >> d5 >> d7;

  long long ans = b*n;

  vector<bool> prime(1e6, 1);
  for(long long i = 2; i < 1e6; i++) if(prime[i]) for(long long j = i*i; j < 1e6; j += i) prime[j] = 0;

  auto cost = [&](string l) {
    long long inc = 0;

    if(prime[stoi(l)]) inc += stoi(l)+p;

    for(auto c : l){
      if(c == '2') inc += d2;
      if(c == '3') inc += d3;
      if(c == '5') inc += d5;
      if(c == '7') inc += d7;
    }

    long long sum = 0, prod = 1;
    for(auto c : l){
      sum += c-'0';
      prod *= (long long)(c-'0');
    }

    if(prime[sum]) inc += sum;
    if(prime[prod]) inc += prod;

    return inc;
  };

  for(auto l : v){
    long long best = cost(l);

    for(int j = 0; j < l.size(); j++){
      auto start = l[j];
      for(int i = 0; i <= 9; i++){
        if(j == 0 && i == 0) continue;
        if('0'+i == start) continue;

        l[j] = '0'+i;
        best = max(best, cost(l));
        l[j] = start;
      }
    }
    
    ans += best;
  }

  cout << ans;
}