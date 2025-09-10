#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
  int n; cin >> n;

  long long tot = 0, best = 0, ans = -1e18;
  for(int i = 0; i < n; i++){
    int a; cin >> a;
    tot += a;
    ans = max(ans, tot-best);
    best = min(best, tot);
  }

  cout << ans;
}