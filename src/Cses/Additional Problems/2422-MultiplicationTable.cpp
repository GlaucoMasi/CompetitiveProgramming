#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  long long n; cin >> n;
  long long l = 0, r = n*n;
  while(l < r-1){
    long long m = l + (r-l)/2;

    long long tot = 0;
    for(long long i = 1; i <= n; i++) tot += min(n, m/i);

    if(tot <= n*n/2LL) l = m;
    else r = m;
  }

  cout << r;
}