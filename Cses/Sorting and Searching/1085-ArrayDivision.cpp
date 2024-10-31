#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
  int n, k;
  cin >> n >> k;

  int biggest = 0;
  vector<long long> v(n);
  for(int i = 0; i < n; i++){
    cin >> v[i];
    biggest = max(biggest, (int)v[i]);
    if(i) v[i] += v[i-1];
  }

  long long l = biggest-1, r = 1e15;
  while(l < r-1){
    long long m = l + (r-l)/2;

    int tot = 1;
    long long last = 0;
    for(int i = 0; i < n; i++){
      if(v[i]-last > m){
        tot++;
        last = v[i-1];
      }
    }

    if(tot <= k) r = m;
    else l = m;
  }

  cout << l+1;
}