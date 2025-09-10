#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  int n; cin >> n;
  vector<int> pres(1e6+1);
  while(n--){
    int a; cin >> a;
    pres[a]++;
  }

  vector<long long> primes;
  vector<int> fact(1e6+1, 0);
  for(long long i = 2; i <= 1e6; i++){
    if(!fact[i]) primes.push_back(i), fact[i] = i;
    for(int j = 0; j < primes.size() && i*primes[j] <= 1e6; j++){
      fact[i*primes[j]] = primes[j];
      if(!(i%primes[j])) break;
    }
  }

  vector<int> mob(1e6+1); mob[1] = 1;
  for(int i = 2; i <= 1e6; i++){
    if(fact[i] == fact[i/fact[i]]) mob[i] = 0;
    else mob[i] = -1*mob[i/fact[i]];
  }

  long long ans = 0;
  for(int i = 1; i <= 1e6; i++){
    long long div = 0;
    for(int j = i; j <= 1e6; j += i) div += pres[j];
    ans += mob[i]*div*(div-1)/2;
  }

  cout << ans;
}