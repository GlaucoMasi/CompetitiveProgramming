#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
  int n; cin >> n;
  vector<int> v(n);
  for(auto &i : v) cin >> i;
  
  int r = -1, best = 0;
  set<int> s;
  for(int i = 0; i < n; i++){
    while(r+1 < n && !s.count(v[r+1])) r++, s.insert(v[r]);
    best = max(best, r-i+1);
    s.erase(v[i]);
  }

  cout << best;
}