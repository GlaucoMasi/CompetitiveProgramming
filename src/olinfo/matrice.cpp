#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m; cin >> n >> m;
  vector<int> righe(n), colonne(m);

  set<int> primes;
  vector<int> ok(1e5+10);
  int i = 2;
  while(1){
    if(!ok[i]){
      primes.insert(i);
      if(i > 1e5) break;

      long long j = i; j*= i;
      for(j; j < 1e5+10; j += i) ok[j] = 1;
    }

    i++;
  }

  for(int x = 0; x < n; x++){
    for(int y = 0; y < m; y++){
      int a; cin >> a; 
      a = *primes.lower_bound(a)-a;
      righe[x] += a;
      colonne[y] += a;
    }
  }

  int ans = 1e9;
  for(auto i : righe) ans = min(ans, i);
  for(auto i : colonne) ans = min(ans, i);
  cout << ans;
}