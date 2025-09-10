#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  long long t = 1;
  int mod = 1e9+7, n;
  cin >> n;

  while(n--) t = (t*2LL)%mod;
  cout << t;
}