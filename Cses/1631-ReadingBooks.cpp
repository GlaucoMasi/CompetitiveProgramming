#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n; cin >> n;
  
  long long tot = 0, m = 0;
  for(int i = 0; i < n; i++){
    long long a; cin >> a;
    tot += a;
    m = max(m, a);
  }

  cout << max(tot, 2*m);
}