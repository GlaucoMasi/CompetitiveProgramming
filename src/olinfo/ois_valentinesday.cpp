#include <bits/stdc++.h>
using namespace std;
#define watch(x) cout << (#x) << " is " << (x) << endl
ifstream fin("input.txt");
ofstream fout("output.txt");
//fout << "Case #" << t << ": ";

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  
  int n, m, best = 0; cin >> n >> m;

  vector<int> c(n), p(n);
  for(auto &i : c) cin >> i;
  for(auto &i : p) cin >> i;

  for(int i = 0; i < n; i++){
    if(c[i]%2 || p[i] > m) continue;
    best = max(best, c[i]);
  }

  cout << best;
}