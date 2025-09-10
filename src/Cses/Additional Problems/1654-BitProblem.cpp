#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  int n = 20, k, mask = 1<<n; cin >> k;
  vector<int> a(mask), b(mask), c(mask), v(k);

  for(int i = 0; i < k; i++){
    int t; cin >> t; v[i] = t;
    a[t]++; b[t]++; c[t]++;
  }

  for(int i = 0; i < n; i++){
    for(int j = 0; j < mask; j++){
      if(j&(1<<i)) a[j] += a[j^(1<<i)];
    }
  }

  for(int i = 0; i < n; i++){
    for(int j = 0; j < mask; j++){
      if((j&(1<<i)) == 0) b[j] += b[j^(1<<i)];
    }
  }

  for(auto i : v){
    int t = 0;
    for(int j = 0; j < n; j++) if((i&(1<<j)) == 0) t += (1<<j);
    cout << a[i] << " " << b[i] << " " << k-a[t] << '\n';
  }
}