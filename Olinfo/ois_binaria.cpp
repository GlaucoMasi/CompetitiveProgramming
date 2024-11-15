#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  
  int n; cin >> n;
  long long tot = 0;
  for(int i = 0; i < n; i++){
    long long a, p = 1; cin >> a;
    while(p-1 < a) p *= 2LL;
    tot += p-a-1;
  }

  cout << tot;
}