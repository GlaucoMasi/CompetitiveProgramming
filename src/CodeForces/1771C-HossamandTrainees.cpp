#include <bits/stdc++.h>
using namespace std;

int main() {
  int t; cin >> t;

  vector<int> primes;
  vector<bool> vis(1e5+5, 0);
  for(int i = 2; i < 1e5+5; i++){
    if(vis[i]) continue;
    
    primes.push_back(i);
    for(int j = 2*i; j < 1e5+5; j += i) vis[j] = 1;
  }

  while(t--) {
    int n; cin >> n;
    set<int> found;

    bool ok = 0;
    for(int i = 0; i < n; i++){
      int a, t; cin >> a; t = sqrt(a);

      for(int j = 0; primes[j] <= t; j++){
        if(!(a%primes[j])){
          if(found.count(primes[j])) ok = 1;
          found.insert(primes[j]);
          while(!(a%primes[j])) a /= primes[j];
        }
      }

      if(a != 1){
        if(found.count(a)) ok = 1;
        found.insert(a);
      }
    }

    cout << (ok ? "YES" : "NO") << '\n';
  }
}