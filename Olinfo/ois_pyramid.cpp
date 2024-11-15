#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  int n; cin >> n;

  int l = 1, r = 1e3;
  while(l < r-1){
    int m = l + (r-l)/2;
    if(m*(m+1)*(2*m+1)/6 <= n) l = m;
    else r = m;
  }

  cout << l;
}