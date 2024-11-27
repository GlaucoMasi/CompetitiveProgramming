#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  int n; long long k;
  cin >> n >> k;

  int l = 1, r = n;
  while(l <= r){
    while(k < r-l) cout << l << " ", l++;
    k -= r-l;
    cout << r << " "; r--;
  }
}