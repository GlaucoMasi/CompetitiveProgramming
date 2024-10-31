#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  int n; long long t; cin >> n >> t;
  vector<long long> v(n); for(auto &i : v) cin >> i;
  
  long long l = 0, r = 2e18;
  while(l < r-1){
    long long m = l + (r-l)/2;

    long long prod = 0;
    for(auto i : v){
      prod += m/i;
      if(prod >= t) break;
    }

    if(prod >= t) r = m;
    else l = m;
  }

  cout << l+1;
}